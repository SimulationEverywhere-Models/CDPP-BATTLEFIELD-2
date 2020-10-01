#BeginMacro(count_enemies)
(
if ( ((0,0)~enA = 1 or (0,0)~enB = 1 or (0,0)~enC = 1), statecount (1, ~fs), 0) +
if ( ((0,0)~enA = 2 or (0,0)~enB = 2 or (0,0)~enC = 2), statecount (2, ~fs), 0) +
if ( ((0,0)~enA = 3 or (0,0)~enB = 3 or (0,0)~enC = 3), statecount (3, ~fs), 0) +
if ( ((0,0)~enA = 4 or (0,0)~enB = 4 or (0,0)~enC = 4), statecount (4, ~fs), 0)
)
#EndMacro

#BeginMacro(get_objective)
(
if ( ((0,0)~enA = 1 or (0,0)~enB = 1 or (0,0)~enC = 1), statecount (1, ~fs), 0) +
if ( ((0,0)~enA = 2 or (0,0)~enB = 2 or (0,0)~enC = 2), statecount (2, ~fs), 0) +
if ( ((0,0)~enA = 3 or (0,0)~enB = 3 or (0,0)~enC = 3), statecount (3, ~fs), 0) +
if ( ((0,0)~enA = 4 or (0,0)~enB = 4 or (0,0)~enC = 4), statecount (4, ~fs), 0)
)
#EndMacro

#BeginMacro(combat_rule_1)
(
if ( ((0,0)~enA = 1 or (0,0)~enB = 1 or (0,0)~enC = 1), (
  if ( ((-1,-1)~fs = 1 and (-1,-1)~fa > 0.5 and (-1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,0)~fs = 1 and (-1,0)~fa > 0.5 and (-1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,1)~fs = 1 and (-1,1)~fa > 0.5 and (-1,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,-1)~fs = 1 and (0,-1)~fa > 0.5 and (0,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,1)~fs = 1 and (0,1)~fa > 0.5 and (0,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,-1)~fs = 1 and (1,-1)~fa > 0.5 and (1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,0)~fs = 1 and (1,0)~fa > 0.5 and (1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,1)~fs = 1 and (1,1)~fa > 0.5 and (1,1)~fa >= (0,0)~fa), 1, 0)), 0)
)
#EndMacro

#BeginMacro(combat_rule_2)
(
if ( ((0,0)~enA = 2 or (0,0)~enB = 2 or (0,0)~enC = 2), (
  if ( ((-1,-1)~fs = 1 and (-1,-1)~fa > 0.5 and (-1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,0)~fs = 1 and (-1,0)~fa > 0.5 and (-1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,1)~fs = 1 and (-1,1)~fa > 0.5 and (-1,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,-1)~fs = 1 and (0,-1)~fa > 0.5 and (0,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,1)~fs = 1 and (0,1)~fa > 0.5 and (0,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,-1)~fs = 1 and (1,-1)~fa > 0.5 and (1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,0)~fs = 1 and (1,0)~fa > 0.5 and (1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,1)~fs = 1 and (1,1)~fa > 0.5 and (1,1)~fa >= (0,0)~fa), 1, 0)), 0)
)
#EndMacro

#BeginMacro(combat_rule_3)
(
if ( ((0,0)~enA = 3 or (0,0)~enB = 3 or (0,0)~enC = 3), (
  if ( ((-1,-1)~fs = 1 and (-1,-1)~fa > 0.5 and (-1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,0)~fs = 1 and (-1,0)~fa > 0.5 and (-1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,1)~fs = 1 and (-1,1)~fa > 0.5 and (-1,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,-1)~fs = 1 and (0,-1)~fa > 0.5 and (0,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,1)~fs = 1 and (0,1)~fa > 0.5 and (0,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,-1)~fs = 1 and (1,-1)~fa > 0.5 and (1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,0)~fs = 1 and (1,0)~fa > 0.5 and (1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,1)~fs = 1 and (1,1)~fa > 0.5 and (1,1)~fa >= (0,0)~fa), 1, 0)), 0)
)
#EndMacro

#BeginMacro(combat_rule_4)
(
if ( ((0,0)~enA = 4 or (0,0)~enB = 4 or (0,0)~enC = 4), (
  if ( ((-1,-1)~fs = 1 and (-1,-1)~fa > 0.5 and (-1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,0)~fs = 1 and (-1,0)~fa > 0.5 and (-1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((-1,1)~fs = 1 and (-1,1)~fa > 0.5 and (-1,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,-1)~fs = 1 and (0,-1)~fa > 0.5 and (0,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((0,1)~fs = 1 and (0,1)~fa > 0.5 and (0,1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,-1)~fs = 1 and (1,-1)~fa > 0.5 and (1,-1)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,0)~fs = 1 and (1,0)~fa > 0.5 and (1,0)~fa >= (0,0)~fa), 1, 0) +
  if ( ((1,1)~fs = 1 and (1,1)~fa > 0.5 and (1,1)~fa >= (0,0)~fa), 1, 0)), 0)
)
#EndMacro

#BeginMacro(director_row)
(
 if ( cellPos(1) > round(fractional((0,0)~target_obj) * 100)  , if( (0,-1)~fs != 50 ,40, if((-1,-1)~fs = 0 ,45,35) ) , if( (0,1)~fs != 50 ,20, if((-1,1)~fs = 0 , 15,25) ))
)
#EndMacro

#BeginMacro(director_column)
(
 if (cellPos(0) > trunc((0,0)~target_obj) ,if( (-1,0)~fs != 50, 10, if((-1,-1)~fs = 0, 45,15) ), if( (1,0)~fs != 50, 30, if((1,-1)~fs = 0 ,35, 25) ) )
)
#EndMacro

#BeginMacro(director_row_column)
(

if( cellPos(0) > trunc((0,0)~target_obj)  , if( cellPos(1) > round(fractional((0,0)~target_obj) * 100) , if ((-1,-1)~fs != 50,45, if((-1,0)~fs = 0, 10,40) ), if ((-1,1)~fs != 50,15, if((-1,0)~fs = 0, 10,20) )) ,   if( cellPos(1) > round(fractional((0,0)~target_obj) * 100) ,if((1,-1)~fs != 50, 35, if ((1,0)~fs = 0 , 30, 40) ), if((1,1)~fs != 50, 25,if((1,0)~fs = 0 ,30,20)  )    ) )

)
#EndMacro

#BeginMacro(move_from_west_factor)

rule : { ~direction := if ( (0,-1)~direction = 20, -20, (0,0)~direction) ; } 100                                              { (0,0)~fs = 0 and (0,0)~direction = 0   and (0,-1)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa , 0 )                        and (0,-1)~fa > if ( (-1,0)~direction = 30, (-1,0)~fa, 0)   and (0,-1)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)           and (0,-1)~fa > if( (0,1)~direction = 40 , (0,1)~fa,0)      and (0,-1)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)           and (0,-1)~fa > if ( (1,0)~direction = 10, (1,0)~fa,0)      and (0,-1)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }

#EndMacro

#BeginMacro(move_from_north_west_factor)

rule : { ~direction := if ( (-1,-1)~direction = 25, -25, (0,0)~direction) ;  } 100                                           { (0,0)~fs = 0 and (0,0)~direction = 0   and (-1,-1)~fa > if ((-1,0)~direction = 30, (-1,0)~fa, 0)                              and  (-1,-1)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)   and (-1,-1)~fa > if((0,-1)~direction = 20 , (0,-1)~fa , 0 )       and  (-1,-1)~fa > if((0,1)~direction = 40 , (0,1)~fa,0)    and (-1,-1)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)           and  (-1,-1)~fa > if ((1,0)~direction = 10, (1,0)~fa,0)    and (-1,-1)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }

#EndMacro

#BeginMacro(move_from_north_factor)

rule : { ~direction := if ( (-1,0)~direction = 30, -30, (0,0)~direction) ;  } 100                                           { (0,0)~fs = 0 and (0,0)~direction = 0   and (-1,0)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa , 0 )                         and (-1,0)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)     and (-1,0)~fa > if( (0,-1)~direction = 20 , (0,-1)~fa,0)          and (-1,0)~fa > if ( (0,1)~direction = 40, (0,1)~fa, 0)    and (-1,0)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)            and (-1,0)~fa > if ( (1,0)~direction = 10, (1,0)~fa,0)     and (-1,0)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }

#EndMacro

#BeginMacro(move_from_north_east_factor)

rule : { ~direction := if ( (-1,1)~direction = 35, -35, (0,0)~direction) ;} 100                                               { (0,0)~fs = 0 and (0,0)~direction = 0   and (-1,1)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa , 0 )                         and (-1,1)~fa > if ( (-1,0)~direction = 30, (-1,0)~fa, 0)   and (-1,1)~fa > if((0,-1)~direction = 20, (0,-1)~fa,0)           and (-1,1)~fa > if( (0,1)~direction = 40 , (0,1)~fa,0)      and (-1,1)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)           and (-1,1)~fa > if ( (1,0)~direction = 10, (1,0)~fa,0)      and (-1,1)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }
#EndMacro


#BeginMacro(move_from_east_factor)

rule : { ~direction := if ( (0,1)~direction = 40, -40, (0,0)~direction) ;  } 100                                              { (0,0)~fs = 0 and (0,0)~direction = 0       and (0,1)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa , 0 )                     and  (0,1)~fa > if ( (-1,0)~direction = 30, (-1,0)~fa, 0)     and (0,1)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)          and  (0,1)~fa > if( (0,-1)~direction = 20 , (0,-1)~fa,0)      and (0,1)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)          and  (0,1)~fa > if ( (1,0)~direction = 10, (1,0)~fa,0)        and (0,1)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }

#EndMacro

#BeginMacro(move_from_south_east_factor)

rule : { ~direction := if ( (1,1)~direction = 45, -45 , (0,0)~direction ) ;  } 100                                           { (0,0)~fs = 0 and (0,0)~direction = 0     and (1,1)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa ,0)                          and (1,1)~fa > if ( (-1,0)~direction = 30, (-1,0)~fa, 0)     and (1,1)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)           and (1,1)~fa > if((0,-1)~direction = 20 , (0,-1)~fa, 0)      and (1,1)~fa > if((0,1)~direction = 40 , (0,1)~fa,0)            and (1,1)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)        and (1,1)~fa > if ((1,0)~direction = 10, (1,0)~fa , 0 )  }
#EndMacro

#BeginMacro(move_from_south_factor)

rule : { ~direction := if ( (1,0)~direction = 10, -10, (0,0)~direction) ;  } 100                                             { (0,0)~fs = 0 and (0,0)~direction = 0       and (1,0)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa , 0 )                     and  (1,0)~fa > if ( (-1,0)~direction = 30, (-1,0)~fa,0)     and (1,0)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)           and  (1,0)~fa > if( (0,-1)~direction = 20 , (0,-1)~fa,0)     and (1,0)~fa > if ( (0,1)~direction = 40, (0,1)~fa, 0)          and  (1,0)~fa > if((1,-1)~direction = 15, (1,-1)~fa,0)       and (1,0)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }

#EndMacro


#BeginMacro(move_from_south_west_factor)

rule : { ~direction := if ( (1,-1)~direction = 15, -15, (0,0)~direction) ;  } 100                                            { (0,0)~fs = 0 and (0,0)~direction = 0      and (1,-1)~fa > if((-1,-1)~direction = 25 , (-1,-1)~fa , 0)                      and  (1,-1)~fa > if ((-1,0)~direction = 30, (-1,0)~fa, 0)      and (1,-1)~fa > if((-1,1)~direction = 35, (-1,1)~fa,0)        and  (1,-1)~fa > if((0,-1)~direction = 20, (0,-1)~fa,0)        and (1,-1)~fa > if( (0,1)~direction = 40 , (0,1)~fa,0)        and  (1,-1)~fa > if ( (1,0)~direction = 10, (1,0)~fa,0)        and (1,-1)~fa > if((1,1)~direction = 45 , (1,1)~fa, 0)  }

#EndMacro


#BeginMacro(move_from_west)

rule  : { ~fs := (0,-1)~fs ; ~fa := (0,-1)~fa ; ~target_obj := (0,-1)~target_obj ; ~direction :=0 ; ~enA := (0,-1)~enA ; ~enB := (0,-1)~enB ; ~enC := (0,-1)~enC ; }  { $cf := 0 ; } 0                               {  (0,0)~fs = 0 and (0,-1)~fs >= 1  and (0,-1)~fs <= 4 and (0,-1)~direction = 20 and (0,0)~direction = -20 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; }  { $cf := 0 ; } 0                                              { (0,0)~fs >= 1 and (0,0)~fs <= 4 and (0,1)~fs = 0 and (0,0)~direction = 20 and (0,1)~direction = -20  }
                                                                                                                            
#EndMacro

#BeginMacro(move_from_north_west)

rule  : { ~fs := (-1,-1)~fs ; ~fa := (-1,-1)~fa ; ~target_obj := (-1,-1)~target_obj ; ~direction :=0 ; ~enA := (-1,-1)~enA ; ~enB := (-1,-1)~enB ; ~enC := (-1,-1)~enC ; }  0                            { (0,0)~fs = 0 and (-1,-1)~fs >= 1 and (-1,-1)~fs <= 4 and (-1,-1)~direction = 25 and (0,0)~direction = -25 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 0 ; } 0                                                        { (0,0)~fs >= 1 and (0,0)~fs <= 4 and (1,1)~fs = 0 and (0,0)~direction = 25 and (1,1)~direction = -25  }
                                                                                                                            
#EndMacro

#BeginMacro(move_from_north_east)

rule  : { ~fs := (-1,1)~fs ; ~fa := (-1,1)~fa ; ~target_obj := (-1,1)~target_obj ; ~direction :=0 ; ~enA := (-1,1)~enA ; ~enB := (-1,1)~enB ; ~enC := (-1,1)~enC ;  }  0                             { (0,0)~fs = 0 and (-1,1)~fs >= 1 and (-1,1)~fs <= 4 and (-1,1)~direction = 35 and (0,0)~direction = -35 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 0 ; } 0                                                  { (0,0)~fs >= 1 and (0,0)~fs <= 4 and (1,-1)~fs = 0 and (0,0)~direction = 35 and (1,-1)~direction = -35  }
                                                                                                                            
#EndMacro


#BeginMacro(move_from_south_east)

rule  : { ~fs := (1,1)~fs ; ~fa := (1,1)~fa ; ~target_obj := (1,1)~target_obj ; ~direction :=0 ; ~enA := (1,1)~enA ; ~enB := (1,1)~enB ; ~enC := (1,1)~enC ; }  0                                 {  (0,0)~fs = 0 and (1,1)~fs >=1 and (1,1)~fs <= 4 and (1,1)~direction = 45 and (0,0)~direction = -45 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 0 ; } 0                                                {  (0,0)~fs >= 1 and (0,0)~fs <= 4 and (-1,-1)~fs = 0 and (0,0)~direction = 45 and (-1,-1)~direction = -45  }
                                                                                                                            
#EndMacro

#BeginMacro(move_from_south_west)

rule  : { ~fs := (1,-1)~fs ; ~fa := (1,-1)~fa ; ~target_obj := (1,-1)~target_obj ; ~direction :=0 ; ~enA := (1,-1)~enA ; ~enB := (1,-1)~enB ; ~enC := (1,-1)~enC ;  } 0                          {  (0,0)~fs = 0 and (1,-1)~fs >=1 and (1,-1)~fs <= 4 and (1,-1)~direction = 15 and (0,0)~direction = -15 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 0 ; } 0                                              { (0,0)~fs >= 1 and (0,0)~fs <= 4 and  (-1,1)~fs = 0 and (0,0)~direction = 15 and (-1,1)~direction = -15  }

#EndMacro

#BeginMacro(move_from_east)

rule : { ~fs := (0,1)~fs ; ~fa := (0,1)~fa ; ~target_obj := (0,1)~target_obj ; ~direction :=0 ; ~enA := (0,1)~enA ; ~enB := (0,1)~enB ; ~enC := (0,1)~enC ;  } 0                                { (0,0)~fs = 0 and (0,1)~fs >= 1 and (0,1)~fs <= 4 and (0,1)~direction = 40 and (0,0)~direction = -40  }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 0 ; }   0                                              { (0,0)~fs >= 1 and (0,0)~fs <= 4 and (0,-1)~fs = 0 and (0,0)~direction = 40 and (0,-1)~direction = -40 }

#EndMacro

#BeginMacro(move_from_north)
rule : { ~fs := (-1,0)~fs ; ~fa := (-1,0)~fa ; ~target_obj := (-1,0)~target_obj ; ~direction :=0 ; ~enA := (-1,0)~enA ; ~enB := (-1,0)~enB ; ~enC := (-1,0)~enC ; } 0                                { (0,0)~fs = 0 and (-1,0)~fs >= 1 and (-1,0)~fs <= 4 and (-1,0)~direction = 30 and (0,0)~direction = -30 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; } { $cf := 0 ; }  0                                                    { (0,0)~fs >= 1 and (0,0)~fs <= 4 and (1,0)~fs = 0 and (0,0)~direction = 30 and (1,0)~direction = -30 }
#EndMacro

#BeginMacro(move_from_south)

rule : { ~fs := (1,0)~fs ; ~fa := (1,0)~fa ; ~direction := 0 ; ~target_obj := (1,0)~target_obj ; } 0                                 { (0,0)~fs = 0 and (1,0)~fs >= 1 and (1,0)~fs <= 4 and (1,0)~direction = 10 and (0,0)~direction = -10 }

rule : { ~fs := 0 ; ~fa := 0 ; ~direction := 0 ; ~target_obj := 0;  ~enA := 0 ; ~enB := 0 ; ~enC := 0 ; }  0                                                 { (0,0)~fs >= 1 and (0,0)~fs <= 4 and (-1,0)~fs = 0 and (0,0)~direction = 10 and (-1,0)~direction = -10  }
#EndMacro
