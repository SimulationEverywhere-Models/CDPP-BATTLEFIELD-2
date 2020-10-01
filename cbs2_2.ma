#include (rules.inc)
[top]
components : cbs2_2

[cbs2_2]
type : cell
dim : (10,10)
delay : transport
defaultDelayTime : 100
border : wrapped

% Moore's neighbourhood is OUR neighbourhood
neighbors : cbs(-1,-1) cbs(-1,0) cbs(-1,1)
neighbors : cbs(0,-1)  cbs(0,0)  cbs(0,1)
neighbors : cbs(1,-1)  cbs(1,0)  cbs(1,1)

InitialValue : 0 
InitialCellsValue : cbs2_2.val
LocalTransition : battlefield

neighborports : fs fa target_obj direction enA enB enC
% fs == fighter status (type of entity); direction == direction of movement
% note that fs and direction are "realistically" all that neighbours could ascertain, ie. they could not nec determine health / fa;
% however, due to movement implementation, should be initializing values only once, and not re-calculating cf every iteration / movement
% fa == fighting ability (health); cf == courage factor; target_obj == target objective
% enA == first enemy (if any); enB == second enemy (if any); enC == third enemy (if any);
% only consider tracking enemies, since actions are not affected if friendly or neutral in this implementation

StateVariables : cf init initObj initBase initEnA initEnB initEnC
StateValues : 0 0 0.00 0.00 0 0 0
InitialVariablesValue : cbs2_2.var

[battlefield]

%================================================ initialization ==========================================================
% read in fs and fa from values assigned from InitialCellValues file; for combatants, set ~cf to normalized value;
rule : { ~fs := trunc((0,0)~fs) ; ~direction := 0 ; ~fa := (round(fractional((0,0)~fa) * 100) +1) ; ~target_obj := 0 ; ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := normal(0.5,0.15) ; $init := -3 ; } 0 { fractional((0,0)~fs) != 0 and trunc((0,0)~fs) <= 4 and $init = -4 }

% read in fs and fa from values assigned from InitialCellValues file; for obstacles / objectives
rule : { ~fs := trunc((0,0)~fs) ; ~direction := 0 ; ~fa := (round(fractional((0,0)~fa) * 100) +1) ; ~target_obj := 0 ; ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 1 ; $init := -3 ; } 0 {  trunc((0,0)~fs) <= 71 and trunc((0,0)~fs) >= 50 and $init = -4 } 

% read in fs and fa from values assigned from InitialCellValues file; for bases
rule : { ~fs := trunc((0,0)~fs) ; ~direction := 0 ; ~fa := (round(fractional((0,0)~fa) * 100) +1) ; ~target_obj := 0 ; ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 1 ; $init := -3 ; } 0 {  trunc((0,0)~fs) <= 40 and trunc((0,0)~fs) >= 10 and $init = -4 } 

% assign an target_objective to move towards, based on courage factor, and values assigned from initialvalues file, stored in bases and target_objectives zones,
% send through ports in each cell, only evaluate first time for fighters when ~target_obj == 0
% if the fighter is cowardly (cf <= 0.5) it will retreat to its own base, as its target_objective, otherwise it will have its mission-assigned target_objective
% if there is a combatant, it must have a base on the battlefield

rule : { ~target_obj := (if (($cf > 0.5), $initObj , $initBase)) ; } { $init := -2 ; } 0 {(0,0)~fs >= 1 and (0,0)~fs <= 4 and $init = -3 }

% transfer initial Enemies list from local state variable, to port
% as this is the last step in the initialization, set the $init variable to zero, so that these steps are not repeated again
% set $initEnA := 0 so that it can be used to calculate values later

rule : { ~enA := $initEnA ; ~enB := $initEnB ; ~enC := $initEnC ; } {$init := -1 ; } 0 { (0,0)~fs >= 1 and (0,0)~fs <= 40 and ($init = -2 or $init = -3) }

rule : { $init } {$init := 0 ; } 0 {(0,0)~fs >= 69 and (0,0)~fs <= 71 and $init < 0 }


%================================== Combatant or Base has an enemy in their neighbourhood =========================================
% combat_rule_1: calculates how many combat-ready (health / ~fa > 0.50) superior (health / ~fa greater than own)
% Side 1 combatants are in neighbourhood, iff Side 1 is in their enemy list. Similarly combat_rule_2 calculates how many
% enemy Side 2 combatants, etc etc. for rules 3 and 4.
% when there is a superior enemy in the neighbourhood, your health / ~fa gets reduced by 10% for each enemy

% if you're on Side 1, look for enemies and their effect on you
rule : { $init } { $init := (((#macro(combat_rule_2)) + (#macro(combat_rule_3)) + (#macro(combat_rule_4))) * 10) ; } 0 
				{ ((0,0)~fs = 10 or (0,0)~fs = 1) and $init = -1 }
	            	            
% if you're on Side 2, look for enemies and their effect on you
rule : { $init } { $init := (((#macro(combat_rule_1)) + (#macro(combat_rule_3)) + (#macro(combat_rule_4))) * 10) ; } 0 
				{ ((0,0)~fs = 20 or (0,0)~fs = 2)  and $init = -1 }
	            	            
% if you're on Side 3, look for enemies and their effect on you
rule : { $init } { $init := (((#macro(combat_rule_2)) + (#macro(combat_rule_1)) + (#macro(combat_rule_4))) * 10) ; } 0 
				{ ((0,0)~fs = 30 or (0,0)~fs = 3)  and $init = -1 }

% if you're on Side 4, look for enemies and their effect on you
rule : { $init } { $init := (((#macro(combat_rule_2)) + (#macro(combat_rule_3)) + (#macro(combat_rule_1))) * 10) ; } 0 
				{ ((0,0)~fs = 40 or (0,0)~fs = 4) and $init = -1 }

% reduce health by amount of superior enemies in vicinity, if our health is greater than damage caused by enemies
rule : { ~fa := trunc((0,0)~fa - $init) ; ~direction := 0 ; } 100
		{ (0,0)~fs >= 1 and (0,0)~fs <= 40 and $init > 0 and (0,0)~fa > $init }

% if overpowered by superior enemies, then DIE
rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ;  } 100 
	            {  (0,0)~fs >= 1 and (0,0)~fs <= 40 and $init > 0 and (0,0)~fa <= $init }

%============================================= Bases or Objectives are NOT attacked =======================================
% bases also have notion of healing when no enemy present
rule : { ~fa := (((0,0)~fa) + 5) ; } 100 {  (0,0)~fs >= 10 and (0,0)~fs <= 40 and (0,0)~fa <= 95 and (#macro(count_enemies)) = 0 }
rule : { ~fa := 100 ; } 100 {  (0,0)~fs >= 10 and (0,0)~fs <= 40 and (0,0)~fa > 95 and (0,0)~fa < 100 and (#macro(count_enemies)) = 0 }

%rule : { ~fs:= (0,0)~fs ; ~fa:= (0,0)~fa ; } 100 {  (0,0)~fs >= 69 and (0,0)~fs <= 71 and (#macro(count_enemies)) = 0 }


%============================================= Objectives being challenged ================================================
rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; } 100 { (0,0)~fs >= 69 and (0,0)~fs <= 71 and (statecount (1, ~fs) > 0 or statecount (2, ~fs) > 0 or statecount (3, ~fs) > 0 or statecount (4, ~fs) > 0 ) }

%============================================= Combatant has no enemy in their neighbourhood ==============================
% notion of healing when no enemy present
% takes longer to heal than to get damaged; ie. heal in increments of 5 every 100 time units

rule : { ~fa := (((0,0)~fa) + 5) ; }  100 
				{  (0,0)~fs >= 1  and (0,0)~fs <= 4 and (0,0)~fa <= 95 and (#macro(count_enemies)) = 0 }
rule : { ~fa := 100 ; }  100 
				{  (0,0)~fs >= 1  and (0,0)~fs <= 4 and (0,0)~fa > 95 and (0,0)~fa < 100 and (#macro(count_enemies)) = 0 }

%============================================= Moving directions ==========================================================
% determine direction in which to move
% movement rules have not changed from previous implementations; uses Moore's neighbourhood
% movement does not avoid /seek out enemies

rule : { ~fs := (0,0)~fs ; ~fa := (0,0)~fa ; ~direction := (#macro(director_row)) ; }  0 
			{ (0,0)~fs >= 1 and (0,0)~fs <=4 and (#macro(count_enemies)) = 0 and (0,0)~direction = 0 and         
               (0,0)~target_obj >= 0 and cellPos(0) = trunc((0,0)~target_obj ) and             
               cellPos(1) != round(fractional((0,0)~target_obj) * 100) }
                                                           
rule : { ~fs := (0,0)~fs ; ~fa := (0,0)~fa ; ~direction := (#macro(director_column)) ; } 0 
			{ (0,0)~fs >= 1 and (0,0)~fs <=4 and (#macro(count_enemies)) = 0 and (0,0)~direction = 0 and        
			   (0,0)~target_obj >= 0 and cellPos(0) != trunc((0,0)~target_obj) and   
              cellPos(1) = round(fractional((0,0)~target_obj) * 100) } 

rule : { ~fs := (0,0)~fs ; ~fa := (0,0)~fa ; ~direction := (#macro(director_row_column)) ; } 0
			{ (0,0)~fs >= 1 and (0,0)~fs <=4 and (#macro(count_enemies)) = 0 and (0,0)~direction = 0 and
			  (0,0)~target_obj >= 0 and cellPos(0) != trunc((0,0)~target_obj) and   
			  cellPos(1) != round(fractional((0,0)~target_obj) * 100) }

%============================================= Move into free cells =======================================================

#macro(move_from_west_factor)
#macro(move_from_west)

#macro(move_from_north_west_factor)
#macro(move_from_north_west)

#macro(move_from_north_east_factor)
#macro(move_from_north_east)

#macro(move_from_south_east_factor)
#macro(move_from_south_east)

#macro(move_from_south_west_factor)
#macro(move_from_south_west)

#macro(move_from_east_factor)
#macro(move_from_east) 

#macro(move_from_north_factor)
#macro(move_from_north) 

#macro(move_from_south_factor)
#macro(move_from_south)
%==========================================================================================================================


%============================================= If none of the above rules evaluate ========================================
rule : { 0 } 100 { t }
