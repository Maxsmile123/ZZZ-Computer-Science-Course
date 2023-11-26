// Решите поставленную задачу в формате четвёрок
00, ,<,start
start,|,<,start
start, ,<,skip
skip,|,<,start1
start1,|,<,start1
start1, ,>,left
left,|,>,check

// if the last left |
check, ,>,fin1
fin1,|,>,fin1
fin1, ,>,fin2
fin2, ,|,fin3
fin3,|,>,fin4
fin4, ,#,fin4


// if its not the last |
check,|,<,go_back

//skip first |, but place one ряд
go_back,|,=,skip_but
skip_but,|,>,next1

del,|, ,next
next, ,>,next1
next1,|,>,next1
next1, ,>,right

right,|,>,check1

// if its not the last | (right side)
check1,|,<,go_back1
go_back1,|,=,del1
del1,|, ,next2
next2,>,|,next2
next2, ,>,next3
next3,|,>,next3
next3, ,>,next4
next4,|,>,next4
next4, ,=,setval1
setval1, ,|,go_back2
go_back2,|,<,go_back2
go_back2, ,<,go_back3
go_back3,|,<,go_back3
go_back3, ,>,right

//if it is
check1, ,<,back
back,|,<,reset
reset, ,|,back1
back1,|,<,reset
reset,|,>,space
space,|, ,space
space, ,<,skip10

//
skip10,|,<,skip101
skip101,|,<,skip102
skip102, ,>,lft
lft,|,>,lft1
lft1,|,>,lft1
lft1, ,>,lft2
lft2,|,>,lft2
lft2, ,>,lft3
lft3,|,>,lft3
lft3, ,|,lft4
lft4,|,>,lft5
lft5, ,#,lft5

skip102,|,>,skip103
skip103,|,>,skipl
skipl,|,<,skipl
skipl, ,>,skip11

skip11,|,>,skip12
skip12,|,>,check10

// if the last left |
check10, ,<,return_f
return_f,|,<,return_f1
return_f1, ,|,move
move,|,<,return_f1
return_f1,|,<,left_side
left_side, ,<,left_side


// if its not the last |
check10,|,<,gback
gback,|, ,mvr
mvr,|,>,mvr
mvr, ,>,nx1
nx1,|,>,nx1
nx1, ,>,nx2
nx2,|,>,check20

check20,|,<,gb
gb,|, ,mvr1
mvr1, ,>,mvr1
mvr1,|,>,mvr2
mvr2,|,>,mvr2
mvr2, ,>,mvr3
mvr3,|,>,mvr3
mvr3, ,|,gb1
gb1,|,<,gb1
gb1, ,<,gb2
gb2,|,<,gb2
gb2, ,>,gb3
gb3,|,>,check20

check20, ,<,check21
check21,|,<,rs
rs, ,|,rb
rb,|,<,rs
rs,|,>,place_space
place_space,|, ,rb1
rb1, ,<,rb2
rb2,|,<,rb3
rb3,|,<,rb3
rb3, ,<,rb4
rb4, ,<,rb4
rb4,|,<,rb5
rb5, ,>,rb6

rb6,|,>,rb7
rb7, ,>,rb7
rb7,|,>,ch

ch, ,<,final_reset
final_reset,|,<,fr
fr, ,|,gol
gol,|,<,fr
fr,|,<,left_side_finish
left_side_finish, ,>,lsf1
lsf1,|,>,lsf1
lsf1, ,>,lsf2
lsf2,|,>,lsf2
lsf2, ,>,lsf3
lsf3,|,>,lsf3
lsf3, ,|,right_one_step
right_one_step,|,>,ros1
ros1, ,#,ros1

ch,|,<,gor
gor,|, ,gor1
gor1, ,>,gor2
gor2,|,>,gor2
gor2, ,>,nx2
