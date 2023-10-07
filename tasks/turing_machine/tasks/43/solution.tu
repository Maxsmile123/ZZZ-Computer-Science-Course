// Решите поставленную задачу в формате четвёрок

00, ,<,00
00,0,=,check_if_<_3
00,1,=,check_if_<_3

// проверка размера числа

check_if_<_3,0,<,check_if_<_3.0
check_if_<_3,1,<,check_if_<_3.1


check_if_<_3.0,0,<,check_if_<_3.00
check_if_<_3.0,1,<,check_if_<_3.10
check_if_<_3.0, ,>,return_to_start

check_if_<_3.1,0,<,check_if_<_3.01
check_if_<_3.1,1,<,check_if_<_3.11
check_if_<_3.1, ,>,check_true_1


check_if_<_3.00,0,<,check_if_<_3.000
check_if_<_3.00,1,<,check_if_<_3.100
check_if_<_3.00, ,>,return_to_start

check_if_<_3.01,0,<,check_if_<_3.001
check_if_<_3.01,1,<,check_if_<_3.101
check_if_<_3.01, ,>,check_true_1

check_if_<_3.10,0,<,check_if_<_3.010
check_if_<_3.10,1,<,check_if_<_3.110
check_if_<_3.10, ,>,check_true_2

check_if_<_3.11,0,<,check_if_<_3.011
check_if_<_3.11,1,<,check_if_<_3.111
check_if_<_3.11, ,>,check_true_3


check_if_<_3.000,0,<,check_if_<_3.000
check_if_<_3.000,1,>,return_to_start
check_if_<_3.000, ,>,return_to_start 

check_if_<_3.001,0,<,check_if_<_3.001
check_if_<_3.001,1,>,return_to_start
check_if_<_3.001, ,>,check_true_1

check_if_<_3.010,0,<,check_if_<_3.010
check_if_<_3.010,1,>,return_to_start
check_if_<_3.010, ,>,check_true_2

check_if_<_3.011,0,<,check_if_<_3.011
check_if_<_3.011,1,>,return_to_start
check_if_<_3.011, ,>,check_true_3

check_if_<_3.100,0,<,check_if_<_3.100
check_if_<_3.100,1,>,return_to_start
check_if_<_3.100, ,>,check_true_4

check_if_<_3.101,0,<,check_if_<_3.101
check_if_<_3.101,1,>,return_to_start
check_if_<_3.101, ,>,check_true_5

check_if_<_3.110,0,<,check_if_<_3.110
check_if_<_3.110,1,>,return_to_start
check_if_<_3.110, ,>,check_true_6

check_if_<_3.111,0,<,check_if_<_3.111
check_if_<_3.111,1,>,return_to_start
check_if_<_3.111, ,>,check_true_7

// если знаков <4 или после числа максимум 3 знака идут только нули

check_true_1,0,>,check_true_1
check_true_1,1,>,check_true_1
check_true_1, ,>,check_true_1_put
check_true_1_put, ,1,end


check_true_2,0,>,check_true_2
check_true_2,1,>,check_true_2
check_true_2, ,>,check_true_2_put
check_true_2_put, ,2,end


check_true_3,0,>,check_true_3
check_true_3,1,>,check_true_3
check_true_3, ,>,check_true_3_put
check_true_3_put, ,>,end


check_true_4,0,>,check_true_4
check_true_4,1,>,check_true_4
check_true_4, ,>,check_true_4_put
check_true_4_put, ,4,end


check_true_5,0,>,check_true_5
check_true_5,1,>,check_true_5
check_true_5, ,>,check_true_5_put
check_true_5_put, ,5,end


check_true_6,0,>,check_true_6
check_true_6,1,>,check_true_6
check_true_6, ,>,check_true_6_put
check_true_6_put, ,6,end


check_true_7,0,>,check_true_7
check_true_7,1,>,check_true_7
check_true_7, ,>,check_true_7_put
check_true_7_put, ,7,end


// если знаков больше чем три, возвращаемся в начало

return_to_start,0,>,return_to_start
return_to_start,1,>,return_to_start
return_to_start, ,<,count3


// если знаков больше чем 3 или любое кол-во нулей, то мы просто считаем

count3,0,<,c3.0
count3,1,<,c3.1
count3, ,>,skip.place.reverse.if.last

c3.0,0,<,c3.00
c3.0,1,<,c3.10

c3.1,0,<,c3.01
c3.1,1,<,c3.11

// ставим пробел вместо последней цифры тройки

c3.00,0, ,c3.000
c3.00,1, ,c3.100

c3.01,0, ,c3.001
c3.01,1, ,c3.101

c3.10,0, ,c3.010
c3.10,1, ,c3.110 

c3.11,0, ,c3.011
c3.11,1, ,c3.111

// перемещаемся вправо до пробела, пропускаем его, и выполняем алгоритм перевода 3значного 2 числа в
// цифру 8ричной

c3.000, ,>,skip.place.000
skip.place.000,0,>,skip.place.000
skip.place.000,1,>,skip.place.000
skip.place.000, ,>,place.000

place.000,0,>,place.000
place.000,1,>,place.000
place.000,2,>,place.000
place.000,3,>,place.000
place.000,4,>,place.000
place.000,5,>,place.000
place.000,6,>,place.000
place.000,7,>,place.000
place.000, ,0,r0


c3.001, ,>,skip.place.001
skip.place.001,0,>,skip.place.001
skip.place.001,1,>,skip.place.001
skip.place.001, ,>,place.001

place.001,0,>,place.001
place.001,1,>,place.001
place.001,2,>,place.001
place.001,3,>,place.001
place.001,4,>,place.001
place.001,5,>,place.001
place.001,6,>,place.001
place.001,7,>,place.001
place.001, ,1,r0


c3.010, ,>,skip.place.010
skip.place.010,0,>,skip.place.010
skip.place.010,1,>,skip.place.010
skip.place.010, ,>,place.010

place.010,0,>,place.010
place.010,1,>,place.010
place.010,2,>,place.010
place.010,3,>,place.010
place.010,4,>,place.010
place.010,5,>,place.010
place.010,6,>,place.010
place.010,7,>,place.010
place.010, ,2,r0


c3.011, ,>,skip.place.011
skip.place.011,0,>,skip.place.011
skip.place.011,1,>,skip.place.011
skip.place.011, ,>,place.011

place.011,0,>,place.011
place.011,1,>,place.011
place.011,2,>,place.011
place.011,3,>,place.011
place.011,4,>,place.011
place.011,5,>,place.011
place.011,6,>,place.011
place.011,7,>,place.011
place.011, ,3,r0


c3.100, ,>,skip.place.100
skip.place.100,0,>,skip.place.100
skip.place.100,1,>,skip.place.100
skip.place.100, ,>,place.100

place.100,0,>,place.100
place.100,1,>,place.100
place.100,2,>,place.100
place.100,3,>,place.100
place.100,4,>,place.100
place.100,5,>,place.100
place.100,6,>,place.100
place.100,7,>,place.100
place.100, ,4,r1


c3.101, ,>,skip.place.101
skip.place.101,0,>,skip.place.101
skip.place.101,1,>,skip.place.101
skip.place.101, ,>,place.101

place.101,0,>,place.101
place.101,1,>,place.101
place.101,2,>,place.101
place.101,3,>,place.101
place.101,4,>,place.101
place.101,5,>,place.101
place.101,6,>,place.101
place.101,7,>,place.101
place.101, ,5,r1


c3.110, ,>,skip.place.110
skip.place.110,0,>,skip.place.110
skip.place.110,1,>,skip.place.110
skip.place.110, ,>,place.110

place.110,0,>,place.110
place.110,1,>,place.110
place.110,2,>,place.110
place.110,3,>,place.110
place.110,4,>,place.110
place.110,5,>,place.110
place.110,6,>,place.110
place.110,7,>,place.110
place.110, ,6,r1


c3.111, ,>,skip.place.111
skip.place.111,0,>,skip.place.111
skip.place.111,1,>,skip.place.111
skip.place.111, ,>,place.111

place.111,0,>,place.111
place.111,1,>,place.111
place.111,2,>,place.111
place.111,3,>,place.111
place.111,4,>,place.111
place.111,5,>,place.111
place.111,6,>,place.111
place.111,7,>,place.111
place.111, ,7,r1


r0,0,<,r0
r0,1,<,r0
r0,2,<,r0
r0,3,<,r0
r0,4,<,r0
r0,5,<,r0
r0,6,<,r0
r0,7,<,r0
r0, ,<,search.place.r0

r1,0,<,r1
r1,1,<,r1
r1,2,<,r1
r1,3,<,r1
r1,4,<,r1
r1,5,<,r1
r1,6,<,r1
r1,7,<,r1
r1, ,<,search.place.r1

search.place.r0,0,<,search.place.r0
search.place.r0,1,<,search.place.r0
search.place.r0, ,0,moveleft

search.place.r1,0,<,search.place.r1
search.place.r1,1,<,search.place.r1
search.place.r1, ,1,moveleft

moveleft,0,<,count3
moveleft,1,<,count3

// теперь случаи когда остается 1 символ 

c3.0, ,>,skip.place.0
skip.place.0,0,>,skip.place.0
skip.place.0,1,>,skip.place.0
skip.place.0, ,>,place.0

place.0,0,>,place.0
place.0,1,>,place.0
place.0,2,>,place.0
place.0,3,>,place.0
place.0,4,>,place.0
place.0,5,>,place.0
place.0,6,>,place.0
place.0,7,>,place.0
place.0, ,0,skip.place.reverse.if.last


c3.1, ,>,skip.place.1
skip.place.1,0,>,skip.place.1
skip.place.1,1,>,skip.place.1
skip.place.1, ,>,place.1

place.1,0,>,place.1
place.1,1,>,place.1
place.1,2,>,place.1
place.1,3,>,place.1
place.1,4,>,place.1
place.1,5,>,place.1
place.1,6,>,place.1
place.1,7,>,place.1
place.1, ,1,skip.place.reverse.if.last

// когда 2 символа

c3.00, ,>,skip.place.0

c3.01, ,>,skip.place.1

c3.10, ,>,skip.place.10
skip.place.10,0,>,skip.place.10
skip.place.10,1,>,skip.place.10
skip.place.10, ,>,place.10

place.10,0,>,place.10
place.10,1,>,place.10
place.10,2,>,place.10
place.10,3,>,place.10
place.10,4,>,place.10
place.10,5,>,place.10
place.10,6,>,place.10
place.10,7,>,place.10
place.10, ,2,skip.place.reverse.if.last


c3.11, ,>,skip.place.11
skip.place.11,0,>,skip.place.11
skip.place.11,1,>,skip.place.11
skip.place.11, ,>,place.11

place.11,0,>,place.11
place.11,1,>,place.11
place.11,2,>,place.11
place.11,3,>,place.11
place.11,4,>,place.11
place.11,5,>,place.11
place.11,6,>,place.11
place.11,7,>,place.11
place.11, ,3,skip.place.reverse.if.last

// переходим полностью влево и переворачиваем полученное число без нулей.

skip.place.reverse.if.last,0,>,skip.place.reverse.if.last
skip.place.reverse.if.last,1,>,skip.place.reverse.if.last
skip.place.reverse.if.last,2,>,skip.place.reverse.if.last
skip.place.reverse.if.last,3,>,skip.place.reverse.if.last
skip.place.reverse.if.last,4,>,skip.place.reverse.if.last
skip.place.reverse.if.last,5,>,skip.place.reverse.if.last
skip.place.reverse.if.last,6,>,skip.place.reverse.if.last
skip.place.reverse.if.last,7,>,skip.place.reverse.if.last
skip.place.reverse.if.last, ,>,skip.place.reverse

skip.place.reverse,0,>,skip.place.reverse
skip.place.reverse,1,>,skip.place.reverse
skip.place.reverse,2,>,skip.place.reverse
skip.place.reverse,3,>,skip.place.reverse
skip.place.reverse,4,>,skip.place.reverse
skip.place.reverse,5,>,skip.place.reverse
skip.place.reverse,6,>,skip.place.reverse
skip.place.reverse,7,>,skip.place.reverse
skip.place.reverse, ,<,destroy0

// уничтожаем нули #нужна проверка на 2 пробела

destroy0,0, ,destroy0
destroy0, ,<,check.place

check.place,0,=,destroy0
check.place,1,=,reverse.start
check.place,2,=,reverse.start
check.place,3,=,reverse.start
check.place,4,=,reverse.start
check.place,5,=,reverse.start
check.place,6,=,reverse.start
check.place,7,=,reverse.start
check.place, ,>,set0

set0, ,0,end

destroy0,1,=,reverse.start
destroy0,2,=,reverse.start
destroy0,3,=,reverse.start
destroy0,4,=,reverse.start
destroy0,5,=,reverse.start
destroy0,6,=,reverse.start
destroy0,7,=,reverse.start

// REVERSE

reverse.start,1, ,rev.start.1
reverse.start,2, ,rev.start.2
reverse.start,3, ,rev.start.3
reverse.start,4, ,rev.start.4
reverse.start,5, ,rev.start.5
reverse.start,6, ,rev.start.6
reverse.start,7, ,rev.start.7

rev.start.1, ,>,rem1.search
rev.start.2, ,>,rem2.search
rev.start.3, ,>,rem3.search
rev.start.4, ,>,rem4.search
rev.start.5, ,>,rem5.search
rev.start.6, ,>,rem6.search
rev.start.7, ,>,rem7.search


rev.move.left, ,<,rev.move.left

rev.move.left,0,<,rem.move.left.check
rev.move.left,1,<,rem.move.left.check
rev.move.left,2,<,rem.move.left.check
rev.move.left,3,<,rem.move.left.check
rev.move.left,4,<,rem.move.left.check
rev.move.left,5,<,rem.move.left.check
rev.move.left,6,<,rem.move.left.check
rev.move.left,7,<,rem.move.left.check

rem.move.left.check, ,>,final.check

rem.move.left.check,0,>,reverse
rem.move.left.check,1,>,reverse
rem.move.left.check,2,>,reverse
rem.move.left.check,3,>,reverse
rem.move.left.check,4,>,reverse
rem.move.left.check,5,>,reverse
rem.move.left.check,6,>,reverse
rem.move.left.check,7,>,reverse

final.check,0, ,final.search1.0
final.check,1, ,final.search1.1
final.check,2, ,final.search1.2
final.check,3, ,final.search1.3
final.check,4, ,final.search1.4
final.check,5, ,final.search1.5
final.check,6, ,final.search1.6
final.check,7, ,final.search1.7


reverse,0, ,rem0
reverse,1, ,rem1
reverse,2, ,rem2
reverse,3, ,rem3
reverse,4, ,rem4
reverse,5, ,rem5
reverse,6, ,rem6
reverse,7, ,rem7


rem0, ,>,rem0.search1

rem0.search1, ,>,rem0.search1
rem0.search1,1,>,rem0.search
rem0.search1,2,>,rem0.search
rem0.search1,3,>,rem0.search
rem0.search1,4,>,rem0.search
rem0.search1,5,>,rem0.search
rem0.search1,6,>,rem0.search
rem0.search1,7,>,rem0.search

rem0.search,0,>,rem0.search
rem0.search,1,>,rem0.search
rem0.search,2,>,rem0.search
rem0.search,3,>,rem0.search
rem0.search,4,>,rem0.search
rem0.search,5,>,rem0.search
rem0.search,6,>,rem0.search
rem0.search,7,>,rem0.search
rem0.search, ,0,return


rem1, ,>,rem1.search1

rem1.search1, ,>,rem1.search1
rem1.search1,1,>,rem1.search
rem1.search1,2,>,rem1.search
rem1.search1,3,>,rem1.search
rem1.search1,4,>,rem1.search
rem1.search1,5,>,rem1.search
rem1.search1,6,>,rem1.search
rem1.search1,7,>,rem1.search

rem1.search,0,>,rem1.search
rem1.search,1,>,rem1.search
rem1.search,2,>,rem1.search
rem1.search,3,>,rem1.search
rem1.search,4,>,rem1.search
rem1.search,5,>,rem1.search
rem1.search,6,>,rem1.search
rem1.search,7,>,rem1.search
rem1.search, ,1,return


rem2, ,>,rem2.search1

rem2.search1, ,>,rem2.search1
rem2.search1,1,>,rem2.search
rem2.search1,2,>,rem2.search
rem2.search1,3,>,rem2.search
rem2.search1,4,>,rem2.search
rem2.search1,5,>,rem2.search
rem2.search1,6,>,rem2.search
rem2.search1,7,>,rem2.search

rem2.search,0,>,rem2.search
rem2.search,1,>,rem2.search
rem2.search,2,>,rem2.search
rem2.search,3,>,rem2.search
rem2.search,4,>,rem2.search
rem2.search,5,>,rem2.search
rem2.search,6,>,rem2.search
rem2.search,7,>,rem2.search
rem2.search, ,2,return


rem3, ,>,rem3.search1

rem3.search1, ,>,rem3.search1
rem3.search1,1,>,rem3.search
rem3.search1,2,>,rem3.search
rem3.search1,3,>,rem3.search
rem3.search1,4,>,rem3.search
rem3.search1,5,>,rem3.search
rem3.search1,6,>,rem3.search
rem3.search1,7,>,rem3.search

rem3.search,0,>,rem3.search
rem3.search,1,>,rem3.search
rem3.search,2,>,rem3.search
rem3.search,3,>,rem3.search
rem3.search,4,>,rem3.search
rem3.search,5,>,rem3.search
rem3.search,6,>,rem3.search
rem3.search,7,>,rem3.search
rem3.search, ,3,return



rem4, ,>,rem4.search1

rem4.search1, ,>,rem4.search1
rem4.search1,1,>,rem4.search
rem4.search1,2,>,rem4.search
rem4.search1,3,>,rem4.search
rem4.search1,4,>,rem4.search
rem4.search1,5,>,rem4.search
rem4.search1,6,>,rem4.search
rem4.search1,7,>,rem4.search

rem4.search,0,>,rem4.search
rem4.search,1,>,rem4.search
rem4.search,2,>,rem4.search
rem4.search,3,>,rem4.search
rem4.search,4,>,rem4.search
rem4.search,5,>,rem4.search
rem4.search,6,>,rem4.search
rem4.search,7,>,rem4.search
rem4.search, ,4,return


rem5, ,>,rem5.search1

rem5.search1, ,>,rem5.search1
rem5.search1,1,>,rem5.search
rem5.search1,2,>,rem5.search
rem5.search1,3,>,rem5.search
rem5.search1,4,>,rem5.search
rem5.search1,5,>,rem5.search
rem5.search1,6,>,rem5.search
rem5.search1,7,>,rem5.search

rem5.search,0,>,rem5.search
rem5.search,1,>,rem5.search
rem5.search,2,>,rem5.search
rem5.search,3,>,rem5.search
rem5.search,4,>,rem5.search
rem5.search,5,>,rem5.search
rem5.search,6,>,rem5.search
rem5.search,7,>,rem5.search
rem5.search, ,5,return


rem6, ,>,rem6.search1

rem6.search1, ,>,rem6.search1
rem6.search1,1,>,rem6.search
rem6.search1,2,>,rem6.search
rem6.search1,3,>,rem6.search
rem6.search1,4,>,rem6.search
rem6.search1,5,>,rem6.search
rem6.search1,6,>,rem6.search
rem6.search1,7,>,rem6.search

rem6.search,0,>,rem6.search
rem6.search,1,>,rem6.search
rem6.search,2,>,rem6.search
rem6.search,3,>,rem6.search
rem6.search,4,>,rem6.search
rem6.search,5,>,rem6.search
rem6.search,6,>,rem6.search
rem6.search,7,>,rem6.search
rem6.search, ,6,return


rem7, ,>,rem7.search1

rem7.search1, ,>,rem7.search1
rem7.search1,1,>,rem7.search
rem7.search1,2,>,rem7.search
rem7.search1,3,>,rem7.search
rem7.search1,4,>,rem7.search
rem7.search1,5,>,rem7.search
rem7.search1,6,>,rem7.search
rem7.search1,7,>,rem7.search

rem7.search,0,>,rem7.search
rem7.search,1,>,rem7.search
rem7.search,2,>,rem7.search
rem7.search,3,>,rem7.search
rem7.search,4,>,rem7.search
rem7.search,5,>,rem7.search
rem7.search,6,>,rem7.search
rem7.search,7,>,rem7.search
rem7.search, ,7,return


return, ,<,rev.move.left
return,0,<,return
return,1,<,return
return,2,<,return
return,3,<,return
return,4,<,return
return,5,<,return
return,6,<,return
return,7,<,return

// final reverse

final.search1.0, ,>,final.search1.0
final.search1.0,0,>,final.search.0
final.search1.0,1,>,final.search.0
final.search1.0,2,>,final.search.0
final.search1.0,3,>,final.search.0
final.search1.0,4,>,final.search.0
final.search1.0,5,>,final.search.0
final.search1.0,6,>,final.search.0
final.search1.0,7,>,final.search.0

final.search1.1, ,>,final.search1.1
final.search1.1,0,>,final.search.1
final.search1.1,1,>,final.search.1
final.search1.1,2,>,final.search.1
final.search1.1,3,>,final.search.1
final.search1.1,4,>,final.search.1
final.search1.1,5,>,final.search.1
final.search1.1,6,>,final.search.1
final.search1.1,7,>,final.search.1

final.search1.2, ,>,final.search1.2
final.search1.2,0,>,final.search.2
final.search1.2,1,>,final.search.2
final.search1.2,2,>,final.search.2
final.search1.2,3,>,final.search.2
final.search1.2,4,>,final.search.2
final.search1.2,5,>,final.search.2
final.search1.2,6,>,final.search.2
final.search1.2,7,>,final.search.2

final.search1.3, ,>,final.search1.3
final.search1.3,0,>,final.search.3
final.search1.3,1,>,final.search.3
final.search1.3,2,>,final.search.3
final.search1.3,3,>,final.search.3
final.search1.3,4,>,final.search.3
final.search1.3,5,>,final.search.3
final.search1.3,6,>,final.search.3
final.search1.3,7,>,final.search.3

final.search1.4, ,>,final.search1.4
final.search1.4,0,>,final.search.4
final.search1.4,1,>,final.search.4
final.search1.4,2,>,final.search.4
final.search1.4,3,>,final.search.4
final.search1.4,4,>,final.search.4
final.search1.4,5,>,final.search.4
final.search1.4,6,>,final.search.4
final.search1.4,7,>,final.search.4

final.search1.5, ,>,final.search1.5
final.search1.5,0,>,final.search.5
final.search1.5,1,>,final.search.5
final.search1.5,2,>,final.search.5
final.search1.5,3,>,final.search.5
final.search1.5,4,>,final.search.5
final.search1.5,5,>,final.search.5
final.search1.5,6,>,final.search.5
final.search1.5,7,>,final.search.5

final.search1.6, ,>,final.search1.6
final.search1.6,0,>,final.search.6
final.search1.6,1,>,final.search.6
final.search1.6,2,>,final.search.6
final.search1.6,3,>,final.search.6
final.search1.6,4,>,final.search.6
final.search1.6,5,>,final.search.6
final.search1.6,6,>,final.search.6
final.search1.6,7,>,final.search.6

final.search1.7, ,>,final.search1.7
final.search1.7,0,>,final.search.7
final.search1.7,1,>,final.search.7
final.search1.7,2,>,final.search.7
final.search1.7,3,>,final.search.7
final.search1.7,4,>,final.search.7
final.search1.7,5,>,final.search.7
final.search1.7,6,>,final.search.7
final.search1.7,7,>,final.search.7

//

final.search.0,0,>,final.search.0
final.search.0,1,>,final.search.0
final.search.0,2,>,final.search.0
final.search.0,3,>,final.search.0
final.search.0,4,>,final.search.0
final.search.0,5,>,final.search.0
final.search.0,6,>,final.search.0
final.search.0,7,>,final.search.0
final.search.0, ,0,move.number.left

final.search.1,0,>,final.search.1
final.search.1,1,>,final.search.1
final.search.1,2,>,final.search.1
final.search.1,3,>,final.search.1
final.search.1,4,>,final.search.1
final.search.1,5,>,final.search.1
final.search.1,6,>,final.search.1
final.search.1,7,>,final.search.1
final.search.1, ,1,move.number.left

final.search.2,0,>,final.search.2
final.search.2,1,>,final.search.2
final.search.2,2,>,final.search.2
final.search.2,3,>,final.search.2
final.search.2,4,>,final.search.2
final.search.2,5,>,final.search.2
final.search.2,6,>,final.search.2
final.search.2,7,>,final.search.2
final.search.2, ,2,move.number.left

final.search.3,0,>,final.search.3
final.search.3,1,>,final.search.3
final.search.3,2,>,final.search.3
final.search.3,3,>,final.search.3
final.search.3,4,>,final.search.3
final.search.3,5,>,final.search.3
final.search.3,6,>,final.search.3
final.search.3,7,>,final.search.3
final.search.3, ,3,move.number.left

final.search.4,0,>,final.search.4
final.search.4,1,>,final.search.4
final.search.4,2,>,final.search.4
final.search.4,3,>,final.search.4
final.search.4,4,>,final.search.4
final.search.4,5,>,final.search.4
final.search.4,6,>,final.search.4
final.search.4,7,>,final.search.4
final.search.4, ,4,move.number.left

final.search.5,0,>,final.search.5
final.search.5,1,>,final.search.5
final.search.5,2,>,final.search.5
final.search.5,3,>,final.search.5
final.search.5,4,>,final.search.5
final.search.5,5,>,final.search.5
final.search.5,6,>,final.search.5
final.search.5,7,>,final.search.5
final.search.5, ,5,move.number.left

final.search.6,0,>,final.search.6
final.search.6,1,>,final.search.6
final.search.6,2,>,final.search.6
final.search.6,3,>,final.search.6
final.search.6,4,>,final.search.6
final.search.6,5,>,final.search.6
final.search.6,6,>,final.search.6
final.search.6,7,>,final.search.6
final.search.6, ,6,move.number.left

final.search.7,0,>,final.search.7
final.search.7,1,>,final.search.7
final.search.7,2,>,final.search.7
final.search.7,3,>,final.search.7
final.search.7,4,>,final.search.7
final.search.7,5,>,final.search.7
final.search.7,6,>,final.search.7
final.search.7,7,>,final.search.7
final.search.7, ,7,move.number.left

move.number.left,0,<,move.number.left
move.number.left,1,<,move.number.left
move.number.left,2,<,move.number.left
move.number.left,3,<,move.number.left
move.number.left,4,<,move.number.left
move.number.left,5,<,move.number.left
move.number.left,6,<,move.number.left
move.number.left,7,<,move.number.left
move.number.left, ,>,start_remember_digit

// перенос первой цифры

start_remember_digit,1, ,start_remember_digit_1
start_remember_digit,2, ,start_remember_digit_2
start_remember_digit,3, ,start_remember_digit_3
start_remember_digit,4, ,start_remember_digit_4
start_remember_digit,5, ,start_remember_digit_5
start_remember_digit,6, ,start_remember_digit_6
start_remember_digit,7, ,start_remember_digit_7


rd_0_put, ,0,skip_digit


start_remember_digit_1, ,<,start_remember_digit_1

start_remember_digit_1,0,>,start_rd_1_skip_place
start_remember_digit_1,1,>,start_rd_1_skip_place
start_remember_digit_1,2,>,start_rd_1_skip_place
start_remember_digit_1,3,>,start_rd_1_skip_place
start_remember_digit_1,4,>,start_rd_1_skip_place
start_remember_digit_1,5,>,start_rd_1_skip_place
start_remember_digit_1,6,>,start_rd_1_skip_place
start_remember_digit_1,7,>,start_rd_1_skip_place

start_rd_1_skip_place, ,>,rd_1_put
rd_1_put, ,1,skip_digit


start_remember_digit_2, ,<,start_remember_digit_2

start_remember_digit_2,0,>,start_rd_2_skip_place
start_remember_digit_2,1,>,start_rd_2_skip_place
start_remember_digit_2,2,>,start_rd_2_skip_place
start_remember_digit_2,3,>,start_rd_2_skip_place
start_remember_digit_2,4,>,start_rd_2_skip_place
start_remember_digit_2,5,>,start_rd_2_skip_place
start_remember_digit_2,6,>,start_rd_2_skip_place
start_remember_digit_2,7,>,start_rd_2_skip_place

start_rd_2_skip_place, ,>,rd_2_put
rd_2_put, ,2,skip_digit


start_remember_digit_3, ,<,start_remember_digit_3

start_remember_digit_3,0,>,start_rd_3_skip_place
start_remember_digit_3,1,>,start_rd_3_skip_place
start_remember_digit_3,2,>,start_rd_3_skip_place
start_remember_digit_3,3,>,start_rd_3_skip_place
start_remember_digit_3,4,>,start_rd_3_skip_place
start_remember_digit_3,5,>,start_rd_3_skip_place
start_remember_digit_3,6,>,start_rd_3_skip_place
start_remember_digit_3,7,>,start_rd_3_skip_place

start_rd_3_skip_place, ,>,rd_3_put
rd_3_put, ,3,skip_digit


start_remember_digit_4, ,<,start_remember_digit_4

start_remember_digit_4,0,>,start_rd_4_skip_place
start_remember_digit_4,1,>,start_rd_4_skip_place
start_remember_digit_4,2,>,start_rd_4_skip_place
start_remember_digit_4,3,>,start_rd_4_skip_place
start_remember_digit_4,4,>,start_rd_4_skip_place
start_remember_digit_4,5,>,start_rd_4_skip_place
start_remember_digit_4,6,>,start_rd_4_skip_place
start_remember_digit_4,7,>,start_rd_4_skip_place

start_rd_4_skip_place, ,>,rd_4_put
rd_4_put, ,4,skip_digit


start_remember_digit_5, ,<,start_remember_digit_5

start_remember_digit_5,0,>,start_rd_5_skip_place
start_remember_digit_5,1,>,start_rd_5_skip_place
start_remember_digit_5,2,>,start_rd_5_skip_place
start_remember_digit_5,3,>,start_rd_5_skip_place
start_remember_digit_5,4,>,start_rd_5_skip_place
start_remember_digit_5,5,>,start_rd_5_skip_place
start_remember_digit_5,6,>,start_rd_5_skip_place
start_remember_digit_5,7,>,start_rd_5_skip_place

start_rd_5_skip_place, ,>,rd_5_put
rd_5_put, ,5,skip_digit


start_remember_digit_6, ,<,start_remember_digit_6

start_remember_digit_6,0,>,start_rd_6_skip_place
start_remember_digit_6,1,>,start_rd_6_skip_place
start_remember_digit_6,2,>,start_rd_6_skip_place
start_remember_digit_6,3,>,start_rd_6_skip_place
start_remember_digit_6,4,>,start_rd_6_skip_place
start_remember_digit_6,5,>,start_rd_6_skip_place
start_remember_digit_6,6,>,start_rd_6_skip_place
start_remember_digit_6,7,>,start_rd_6_skip_place

start_rd_6_skip_place, ,>,rd_6_put
rd_6_put, ,6,skip_digit


start_remember_digit_7, ,<,start_remember_digit_7

start_remember_digit_7,0,>,start_rd_7_skip_place
start_remember_digit_7,1,>,start_rd_7_skip_place
start_remember_digit_7,2,>,start_rd_7_skip_place
start_remember_digit_7,3,>,start_rd_7_skip_place
start_remember_digit_7,4,>,start_rd_7_skip_place
start_remember_digit_7,5,>,start_rd_7_skip_place
start_remember_digit_7,6,>,start_rd_7_skip_place
start_remember_digit_7,7,>,start_rd_7_skip_place

start_rd_7_skip_place, ,>,rd_7_put
rd_7_put, ,7,skip_digit

// пропуск поставленного числа

skip_digit,0,>,start_move_right
skip_digit,1,>,start_move_right
skip_digit,2,>,start_move_right
skip_digit,3,>,start_move_right
skip_digit,4,>,start_move_right
skip_digit,5,>,start_move_right
skip_digit,6,>,start_move_right
skip_digit,7,>,start_move_right

// переход в цикл

start_move_right, ,>,start_move_right
start_move_right,0,>,check_right_spase
start_move_right,1,>,check_right_spase
start_move_right,2,>,check_right_spase
start_move_right,3,>,check_right_spase
start_move_right,4,>,check_right_spase
start_move_right,5,>,check_right_spase
start_move_right,6,>,check_right_spase
start_move_right,7,>,check_right_spase

// блок с проверкой

check_right_spase, ,<,remember_last_digit_to_move
check_right_spase,0,<,remember_digit_to_move
check_right_spase,1,<,remember_digit_to_move
check_right_spase,2,<,remember_digit_to_move
check_right_spase,3,<,remember_digit_to_move
check_right_spase,4,<,remember_digit_to_move
check_right_spase,5,<,remember_digit_to_move
check_right_spase,6,<,remember_digit_to_move
check_right_spase,7,<,remember_digit_to_move

//

remember_digit_to_move,0, ,rd_to_move_0
remember_digit_to_move,1, ,rd_to_move_1
remember_digit_to_move,2, ,rd_to_move_2
remember_digit_to_move,3, ,rd_to_move_3
remember_digit_to_move,4, ,rd_to_move_4
remember_digit_to_move,5, ,rd_to_move_5
remember_digit_to_move,6, ,rd_to_move_6
remember_digit_to_move,7, ,rd_to_move_7

// двигаем головку вправо

rd_to_move_0, ,<,rd_to_move_0
rd_to_move_0,0,>,rd_0_put
rd_to_move_0,1,>,rd_0_put
rd_to_move_0,2,>,rd_0_put
rd_to_move_0,3,>,rd_0_put
rd_to_move_0,4,>,rd_0_put
rd_to_move_0,5,>,rd_0_put
rd_to_move_0,6,>,rd_0_put
rd_to_move_0,7,>,rd_0_put

rd_to_move_1, ,<,rd_to_move_1
rd_to_move_1,0,>,rd_1_put
rd_to_move_1,1,>,rd_1_put
rd_to_move_1,2,>,rd_1_put
rd_to_move_1,3,>,rd_1_put
rd_to_move_1,4,>,rd_1_put
rd_to_move_1,5,>,rd_1_put
rd_to_move_1,6,>,rd_1_put
rd_to_move_1,7,>,rd_1_put

rd_to_move_2, ,<,rd_to_move_2
rd_to_move_2,0,>,rd_2_put
rd_to_move_2,1,>,rd_2_put
rd_to_move_2,2,>,rd_2_put
rd_to_move_2,3,>,rd_2_put
rd_to_move_2,4,>,rd_2_put
rd_to_move_2,5,>,rd_2_put
rd_to_move_2,6,>,rd_2_put
rd_to_move_2,7,>,rd_2_put

rd_to_move_3, ,<,rd_to_move_3
rd_to_move_3,0,>,rd_3_put
rd_to_move_3,1,>,rd_3_put
rd_to_move_3,2,>,rd_3_put
rd_to_move_3,3,>,rd_3_put
rd_to_move_3,4,>,rd_3_put
rd_to_move_3,5,>,rd_3_put
rd_to_move_3,6,>,rd_3_put
rd_to_move_3,7,>,rd_3_put

rd_to_move_4, ,<,rd_to_move_4
rd_to_move_4,0,>,rd_4_put
rd_to_move_4,1,>,rd_4_put
rd_to_move_4,2,>,rd_4_put
rd_to_move_4,3,>,rd_4_put
rd_to_move_4,4,>,rd_4_put
rd_to_move_4,5,>,rd_4_put
rd_to_move_4,6,>,rd_4_put
rd_to_move_4,7,>,rd_4_put

rd_to_move_5, ,<,rd_to_move_5
rd_to_move_5,0,>,rd_5_put
rd_to_move_5,1,>,rd_5_put
rd_to_move_5,2,>,rd_5_put
rd_to_move_5,3,>,rd_5_put
rd_to_move_5,4,>,rd_5_put
rd_to_move_5,5,>,rd_5_put
rd_to_move_5,6,>,rd_5_put
rd_to_move_5,7,>,rd_5_put

rd_to_move_6, ,<,rd_to_move_6
rd_to_move_6,0,>,rd_6_put
rd_to_move_6,1,>,rd_6_put
rd_to_move_6,2,>,rd_6_put
rd_to_move_6,3,>,rd_6_put
rd_to_move_6,4,>,rd_6_put
rd_to_move_6,5,>,rd_6_put
rd_to_move_6,6,>,rd_6_put
rd_to_move_6,7,>,rd_6_put

rd_to_move_7, ,<,rd_to_move_7
rd_to_move_7,0,>,rd_7_put
rd_to_move_7,1,>,rd_7_put
rd_to_move_7,2,>,rd_7_put
rd_to_move_7,3,>,rd_7_put
rd_to_move_7,4,>,rd_7_put
rd_to_move_7,5,>,rd_7_put
rd_to_move_7,6,>,rd_7_put
rd_to_move_7,7,>,rd_7_put

// если последняя цифра

remember_last_digit_to_move,0, ,rld_to_move_0
remember_last_digit_to_move,1, ,rld_to_move_1
remember_last_digit_to_move,2, ,rld_to_move_2
remember_last_digit_to_move,3, ,rld_to_move_3
remember_last_digit_to_move,4, ,rld_to_move_4
remember_last_digit_to_move,5, ,rld_to_move_5
remember_last_digit_to_move,6, ,rld_to_move_6
remember_last_digit_to_move,7, ,rld_to_move_7

// если последняя цифра (двигаем головку вправо)

rld_to_move_0, ,<,rld_to_move_0
rld_to_move_0,0,>,rld_0_put
rld_to_move_0,1,>,rld_0_put
rld_to_move_0,2,>,rld_0_put
rld_to_move_0,3,>,rld_0_put
rld_to_move_0,4,>,rld_0_put
rld_to_move_0,5,>,rld_0_put
rld_to_move_0,6,>,rld_0_put
rld_to_move_0,7,>,rld_0_put

rld_to_move_1, ,<,rld_to_move_1
rld_to_move_1,0,>,rld_1_put
rld_to_move_1,1,>,rld_1_put
rld_to_move_1,2,>,rld_1_put
rld_to_move_1,3,>,rld_1_put
rld_to_move_1,4,>,rld_1_put
rld_to_move_1,5,>,rld_1_put
rld_to_move_1,6,>,rld_1_put
rld_to_move_1,7,>,rld_1_put

rld_to_move_2, ,<,rld_to_move_2
rld_to_move_2,0,>,rld_2_put
rld_to_move_2,1,>,rld_2_put
rld_to_move_2,2,>,rld_2_put
rld_to_move_2,3,>,rld_2_put
rld_to_move_2,4,>,rld_2_put
rld_to_move_2,5,>,rld_2_put
rld_to_move_2,6,>,rld_2_put
rld_to_move_2,7,>,rld_2_put

rld_to_move_3, ,<,rld_to_move_3
rld_to_move_3,0,>,rld_3_put
rld_to_move_3,1,>,rld_3_put
rld_to_move_3,2,>,rld_3_put
rld_to_move_3,3,>,rld_3_put
rld_to_move_3,4,>,rld_3_put
rld_to_move_3,5,>,rld_3_put
rld_to_move_3,6,>,rld_3_put
rld_to_move_3,7,>,rld_3_put

rld_to_move_4, ,<,rld_to_move_4
rld_to_move_4,0,>,rld_4_put
rld_to_move_4,1,>,rld_4_put
rld_to_move_4,2,>,rld_4_put
rld_to_move_4,3,>,rld_4_put
rld_to_move_4,4,>,rld_4_put
rld_to_move_4,5,>,rld_4_put
rld_to_move_4,6,>,rld_4_put
rld_to_move_4,7,>,rld_4_put

rld_to_move_5, ,<,rld_to_move_5
rld_to_move_5,0,>,rld_5_put
rld_to_move_5,1,>,rld_5_put
rld_to_move_5,2,>,rld_5_put
rld_to_move_5,3,>,rld_5_put
rld_to_move_5,4,>,rld_5_put
rld_to_move_5,5,>,rld_5_put
rld_to_move_5,6,>,rld_5_put
rld_to_move_5,7,>,rld_5_put

rld_to_move_6, ,<,rld_to_move_6
rld_to_move_6,0,>,rld_6_put
rld_to_move_6,1,>,rld_6_put
rld_to_move_6,2,>,rld_6_put
rld_to_move_6,3,>,rld_6_put
rld_to_move_6,4,>,rld_6_put
rld_to_move_6,5,>,rld_6_put
rld_to_move_6,6,>,rld_6_put
rld_to_move_6,7,>,rld_6_put

rld_to_move_7, ,<,rld_to_move_7
rld_to_move_7,0,>,rld_7_put
rld_to_move_7,1,>,rld_7_put
rld_to_move_7,2,>,rld_7_put
rld_to_move_7,3,>,rld_7_put
rld_to_move_7,4,>,rld_7_put
rld_to_move_7,5,>,rld_7_put
rld_to_move_7,6,>,rld_7_put
rld_to_move_7,7,>,rld_7_put

rld_0_put, ,0,end
rld_1_put, ,1,end
rld_2_put, ,2,end
rld_3_put, ,3,end
rld_4_put, ,4,end
rld_5_put, ,5,end
rld_6_put, ,6,end
rld_7_put, ,7,end

// конец

end, ,#,end
end,0,>,end
end,1,>,end
end,2,>,end
end,3,>,end
end,4,>,end
end,5,>,end
end,6,>,end
end,7,>,end











