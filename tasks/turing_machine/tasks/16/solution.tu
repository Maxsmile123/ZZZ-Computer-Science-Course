/ Решите поставленную задачу в формате четвёрок
00, ,<,move


// смещение каретки в крайнее левое положение
move,1,<,move
move,0,<,move

// конец первого, переход ко 2 числу
move, ,<,move2

# Алгоритм копирования 1 числа


// крайнее левое положение, начало копирования
 
move2,1,<,move2
move2,0,<,move2
move2, ,>,change

move2,O,>,change
move2,L,>,change

change,0,O,cop1_0
change,1,L,cop1_1
change, ,>,change2


// копия 0

cop1_0,O,>,cop1_0
cop1_0,0,>,cop1_0
cop1_0,1,>,cop1_0
cop1_0,L,>,cop1_0
cop1_0, ,>,cop2_0

cop2_0,0,>,cop2_0
cop2_0,1,>,cop2_0
cop2_0,L,>,cop2_0
cop2_0, ,>,cop3_0

cop3_0,0,>,cop3_0
cop3_0,1,>,cop3_0
cop3_0,L,>,cop3_0
cop3_0, ,0,cop4_0

cop4_0,1,<,cop4_0
cop4_0,0,<,cop4_0
cop4_0, ,<,move

// копирование 1(единицы)

cop1_1,0,>,cop1_1
cop1_1,1,>,cop1_1
cop1_1,L,>,cop1_1
cop1_1,O,>,cop1_1
cop1_1, ,>,cop2_1

cop2_1,0,>,cop2_1
cop2_1,1,>,cop2_1
cop2_1,O,>,cop2_1
cop2_1,L,>,cop2_1
cop2_1, ,>,cop3_1

cop3_1,0,>,cop3_1
cop3_1,1,>,cop3_1
cop3_1,O,>,cop3_1
cop3_1,L,>,cop3_1
cop3_1, ,1,cop4_1

cop4_1,0,<,cop4_1
cop4_1,1,<,cop4_1
cop4_1, ,<,move

// начало копирования второго числа (замена переменных)

change2,0,O,secCop_0
change2,O,>,change2
change2,L,>,change2
change2,1,L,secCop4_0



// копирование 0

secCop_0,O,>,secCop_0
secCop_0,1,>,secCop_0
secCop_0,0,>,secCop_0
secCop_0, ,>,secCop1_0

secCop1_0,1,>,secCop1_0
secCop1_0,0,>,secCop1_0
secCop1_0, ,>,secCop2_0

secCop2_0, ,0,secCop3_0
secCop2_0,0,>,secCop2_0
secCop2_0,1,>,secCop2_0

secCop3_0,0,<,secCop3_0
secCop3_0,1,<,secCop3_0
secCop3_0,L,<,secCop3_0
secCop3_0,O,<,secCop3_0
secCop3_0, ,<,skip1

skip1,0,<,skip1
skip1,1,<,skip1
skip1, ,<,skip2

skip2,0,<,skip2
skip2,1,<,skip2
skip2,O,=,change2
skip2,L,=,change2

secCop4_0,1,>,secCop4_0
secCop4_0,0,>,secCop4_0
secCop4_0,L,>,secCop4_0
secCop4_0,O,>,secCop4_0
secCop4_0, ,>,secCop5_0

secCop5_0,0,>,secCop5_0
secCop5_0,1,>,secCop5_0
secCop5_0, ,>,secCop6_0

secCop6_0,0,>,secCop6_0
secCop6_0,1,>,secCop6_0
secCop6_0, ,1,secCop7_0

secCop7_0,0,<,secCop7_0
secCop7_0,1,<,secCop7_0
secCop7_0, ,<,secCop8_0

secCop8_0,1,<,secCop8_0
secCop8_0,0,<,secCop8_0
secCop8_0, ,<,secCop9_0

secCop9_0,1,<,secCop9_0
secCop9_0,0,<,secCop9_0

secCop9_0,O,=,change2
secCop9_0,L,=,change2

# алгоритм замена (O на 0) и (L на 1)

change2, ,<,ok1
ok1,L,<,ok1
ok1,O,<,ok1
ok1, ,<,ok2

ok2,L,<,ok2
ok2,O,<,ok2
ok2, ,>,ok3

ok3,O,0,ok4
ok3,L,1,ok4
ok3,0,>,ok3
ok3,1,>,ok3
ok3, ,>,ok5

ok4,0,>,ok3
ok4,1,>,ok3

ok5,O,0,ok3

// сдвиг каретки в крайнее правое положение
ok5,1,>,right
ok5,0,>,right
right,1,>,right
right,0,>,right
right, ,>,right2

right2,1,>,right2
right2,0,>,right2
right2, ,<,01

# Алгоритм арифметики этического сдвига вправо 

01,1,<,01
01,0,<,01
01, ,<,02

02,1,<,02
02,0,<,02
02, ,>,03

// левый край первого числа

03,1, ,04
03,0, ,04
04, ,>,05
05,1,>,05
05,0,>,05
05, ,>,06

// сдвиг на разряд

06,1,>,07
06,0,>,07
07,1,<,08
07,0,<,09
08,1,=,10
08,0,1,10
09,1,0,10
09,0,=,10

10,1,>,11
10,0,>,11
11,1,>,07
11,0,>,07
07, ,<,12
12,1,0,13
12,0,=,13

// возвращаемся к началу числа
 
13,1,<,13
13,0,<,13

// заход на первое число справа

13, ,<,14
14,1,<,14
14,0,<,14
14, ,>,03

// перевод каретки вправо (конец)
 
03, ,>,fin
fin,1,>,fin
fin,0,>,fin
fin, ,#,fin

