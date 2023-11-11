// Решите поставленную задачу в формате четвёрок

# Начало работы
00, ,<,pros

# Алгоритм смещения

begin1,0,<,begin1
begin1,1,0,transl1
transl1,0,>,trans2
begin1, ,>,fin_skip
trans2,0,1,trans2
trans2,1,>,trans2
trans2, ,<,trans3
trans3,1,<,trans3
trans3,0,<,trans3
trans3, ,<,alg
alg,1,0,alg1
alg1,0,>,alg2
alg2, ,<,alg
alg2,0,1,alg3
alg3,1,<,alg
alg,0,<,alg
alg, ,>,alg4
alg4,1,>,alg4
alg4,0,>,alg4
alg4, ,>,alg5
alg5,1,>,alg5
alg5,0,>,alg5
alg5, ,=,begAlg



// begAlg
begAlg,1,>,begAlg
begAlg,0,>,begAlg
begAlg, ,<,begin1

// Смещение каретки в левую сторону
pros,1,<,pros
pros,0,<,pros

// Переход ко 2 числа при смещении каретки влево
pros, ,<,begCop1



# Алгоритм копии первого заданно числа


// Начало копирования числа
begCop1,1,<,begCop1
begCop1,0,<,begCop1
begCop1, ,>,begCop2


begCop1,O,>,begCop2
begCop1,L,>,begCop2

// Копирование первого заданного числа

begCop2,0,O,cop1
begCop2,1,L,1_cop1
begCop2, ,>,2_begCop1

// Копия 0

cop1,O,>,cop1
cop1,L,>,cop1
cop1,0,>,cop1
cop1,1,>,cop1
cop1, ,>,cop2
cop2,0,>,cop2
cop2,1,>,cop2
cop2, ,>,cop3
cop3,0,>,cop3
cop3,1,>,cop3
cop3,O,>,cop3
cop3,L,>,cop3
cop3, ,0,cop4
cop4,1,<,cop4
cop4,0,<,cop4
cop4, ,<,pros

// Копия 1

1_cop1,1,>,1_cop1
1_cop1,0,>,1_cop1
1_cop1,L,>,1_cop1
1_cop1,O,>,1_cop1
1_cop1, ,>,1_cop2
1_cop2,1,>,1_cop2
1_cop2,0,>,1_cop2
1_cop2, ,>,1_cop3
1_cop3,1,>,1_cop3
1_cop3,0,>,1_cop3
1_cop3, ,1,1_cop4
1_cop4,0,<,1_cop4
1_cop4,1,<,1_cop4
1_cop4, ,<,pros


# Алгоритм копии второго заданного числа


// Начало копии 2 числа. Замена 0 на O, 1 на L
2_begCop1,0,O,2_begCop2
2_begCop1,1,L,2_cop4
2_begCop1,O,>,2_begCop1
2_begCop1,L,>,2_begCop1

// Копия 0
2_begCop2,O,>,2_begCop2
2_begCop2,1,>,2_begCop2
2_begCop2,0,>,2_begCop2
2_begCop2, ,>,2_cop1
2_cop1,1,>,2_cop1
2_cop1,0,>,2_cop1
2_cop1, ,>,2_cop2
2_cop2, ,0,2_cop3
2_cop2,0,>,2_cop2
2_cop2,1,>,2_cop2
2_cop3,O,<,2_cop3
2_cop3,L,<,2_cop3
2_cop3,1,<,2_cop3
2_cop3,0,<,2_cop3
2_cop3, ,<,skip1

// Пропуск первого заданного скопированного числа
skip1,0,<,skip1
skip1,1,<,skip1
skip1, ,<,skip2
skip2,1,<,skip2
skip2,0,<,skip2

// Копия 1
skip2,O,=,2_begCop1
skip2,L,=,2_begCop1
skip2, ,>,2_begCop1
2_cop4,0,>,2_cop4
2_cop4,1,>,2_cop4
2_cop4,L,>,2_cop4
2_cop4,O,>,2_cop4
2_cop4, ,>,2_cop5
2_cop5,1,>,2_cop5
2_cop5,0,>,2_cop5
2_cop5, ,>,2_cop6
2_cop6,0,>,2_cop6
2_cop6,1,>,2_cop6
2_cop6, ,1,2_cop7
2_cop7,1,<,2_cop7
2_cop7,0,<,2_cop7
2_cop7, ,<,2_cop8
2_cop8,1,<,2_cop8
2_cop8,0,<,2_cop8
2_cop8, ,<,2_cop9
2_cop9,1,<,2_cop9
2_cop9,0,<,2_cop9
2_cop9,L,=,2_begCop1
2_cop9,O,=,2_begCop1


# Алгоритм раскодировки (перевод из L и O в 0 и 1, возвращение заданного числа)


// Раскодировка первого заданного числа

2_begCop1, ,<,decod1
decod1,L,<,decod1
decod1,O,<,decod1
decod1, ,<,decod2
decod2,L,<,decod2
decod2,O,<,decod2
decod2, ,>,decod3
decod3,L,1,decod4
decod3,0,>,decod3
decod3,1,>,decod3
decod3,O,0,decod4
decod3, ,>,2_decod1
decod4,0,<,decod4
decod4,1,<,decod4
decod4,L,<,decod4
decod4,O,<,decod4
decod4, ,=,decod2

// Раскодировка второго заданного числа


2_decod1,O,0,2_decod2
2_decod1,0,>,2_decod1
2_decod1,L,1,2_decod1
2_decod1,1,>,2_decod1
2_decod1, ,>,2_decod3
2_decod2,O,<,2_decod2
2_decod2,L,<,2_decod2
2_decod2,0,<,2_decod2
2_decod2,1,<,2_decod2
2_decod2, ,=,decod3

// Возвращение каретки на правый край

2_decod3,1,>,2_decod3
2_decod3,0,>,2_decod3
2_decod3, ,>,2_decod4
2_decod4,1,>,2_decod4
2_decod4,0,>,2_decod4
2_decod4, ,=,begAlg

fin_skip,0,>,fin_skip
fin_skip, ,<,zero1 # Затирание промежуточных вычислений
zero1,0, ,zero2
zero1, ,<,fin
zero2, ,<,zero3
zero3,0, ,zero4
zero3, ,<,fin
zero4, ,<,zero5
zero5,0, ,zero6
zero5, ,<,fin
zero6, ,<,zero7
zero7,0, ,zero8
zero7, ,<,fin
zero8, ,<,zero9
zero9,0, ,zero10
zero9, ,<,fin
zero10, ,<,zero11
zero11,0, ,zero12
zero11, ,<,fin
zero12, ,<,zero13
zero13,0, ,zero14
zero13, ,<,fin
zero14, ,<,zero15
zero15,0, ,zero16
zero15, ,<,fin
zero16, ,<,fin
fin,0,>,fin
fin,1,>,fin

fin, ,#,fin
