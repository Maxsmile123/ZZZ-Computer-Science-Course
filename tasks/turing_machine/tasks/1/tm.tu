//Блок сдвига
//Изначально головка за 2 числами фиксированной длины
//Мы возвращаем головку к началу первого числа
0, ,<,70
70,0,<,70
70,1,<,70
70, ,<,71
71,0,<,70
71,1,<,70
71, ,>,72
72, ,>,1
//Блок работы с захватом первого символа первого числа
//Мы в начале первого слова
1,0,a,40
1,1,b,44
40,a,>,2
//Захватили первый элемент 1 заменили на b а 0 заменили на a
2,0,>,2
2,1,>,2
2,a,>,2
2,b,>,2
2, ,>,3
//Добежали до конца первого числа
3,0,a,41
3,1,b,41
//Блок захвата символа из второго числа
//Выполнили захват соответстующего элемента второго
//числа и бежим до конца второго числа
3,a,>,3
3,b,>,3
3, ,>,15
41,a,>,4
41,b,>,4
4,0,>,4
4,1,>,4
4, ,>,5
5,0,>,5
5,1,>,5
//Добежали до конца
5, ,0,42
//В пробел вписали с отступом результат конъюнкции
//Остальные строчки кода до следующего комментария
//Те же самые действия просто в зависимости от захвата
// разных элементов разные резльтаты 0 или 1
42,0,<,6
42,1,<,6
6,0,<,6
6,1,<,6
6,a,<,6
6,b,<,6
6, ,<,7
7,0,<,6
7,1,<,6
7,a,<,6
7,b,<,6
7, ,>,8
8, ,>,80
80,0,a,40
80,a,>,80
80,b,>,80
80,1,b,43
80, ,>,90 
43,b,>,9
9,0,>,9
9,1,>,9
9,a,>,9
9,b,>,9
9, ,>,10
10,0,a,41
10,a,>,10
10,b,>,10
10,1,b,46
46,b,>,11
11,0,>,11
11,1,>,11
11, ,>,12
12,0,>,12
12,1,>,12
12, ,1,42
44,b,>,13
13,0,>,13
13,1,>,13
13,a,>,13
13,b,>,13
13, ,>,14
14,0,a,41
14,1,b,46
14,a,>,14
14,b,>,14
14, ,>,15 
//Блок восстановления к исходным данным
//Восстанавливаем замененные символы на исходники
// Идем назад и возвращаем
15,0,<,15
15,1,<,15
15,a,0,45
45,0,<,15
45,1,<,15
15,b,1,45
15, ,<,16
16,0,<,15
16,1,<,15
16,a,0,45
16,b,1,45
16, ,<,17
17,0,<,15
17,1,<,15
17,a,0,45
17,b,1,45
17, ,<,18
18,0,<,15
18,1,<,15
18,a,0,45
18,b,1,45
18, ,<,19
19,0,<,15
19,1,<,15
19,a,0,45
19,b,1,45
19, ,>,20
//Головка ушла вперед на несколько пробелов и
//возвращаем ее на первое слово начало
20, ,>,20
20,0,>,100
20,1,>,100
100, ,>,101
100,1,>,100
100,0,>,100
101, ,<,102
102, ,#,102
101,0,>,100
101,1,>,100
10, ,>,15
90,a,>,90 
90,0,>,90
90,1,>,90
90,b,>,90
90, ,<,15 
