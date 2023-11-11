// Решите поставленную задачу в формате четвёрок

00, ,<,mv1_start

//  КОПИРОВАНИЕ ПЕРВОГО С НАЧАЛА ЧИСЛА ( 1 )

# ПЕРЕМЕЩЕНИЕ К НАЧАЛУ СТРОКИ

mv1_start,1,<,mv1_start  mv1_start,0,<,mv1_start  mv1_start, ,<,mv2_start
mv2_start,1,<,mv2_start  mv2_start,0,<,mv2_start  mv2_start, ,>,opr1

# ОПРЕДЕЛЯЕМ ЦИФЕРКО

opr1,1, ,pr1_mv1_1  opr1,0, ,pr1_mv1_0  opr1, ,>,opr2

# ПИШЕМ ЕДИНИЧКУ ( 1 )

pr1_mv1_1, ,>,pr1_mv2_1
pr1_mv2_1,1,>,pr1_mv2_1  pr1_mv2_1,0,>,pr1_mv2_1  pr1_mv2_1, ,>,pr1_mv3_1
pr1_mv3_1,1,>,pr1_mv3_1  pr1_mv3_1,0,>,pr1_mv3_1  pr1_mv3_1, ,>,pr1_mv4_1
pr1_mv4_1,1,>,pr1_mv4_1  pr1_mv4_1,0,>,pr1_mv4_1  pr1_mv4_1, ,1,pr1_mv1_obr

# ИДЕМ ОБРАТНО В НАЧАЛО ПЕРВОГО СЛОВА

pr1_mv1_obr,1,<,pr1_mv1_obr  pr1_mv1_obr,0,<,pr1_mv1_obr  pr1_mv1_obr, ,<,pr1_mv2_obr
pr1_mv2_obr,1,<,pr1_mv2_obr  pr1_mv2_obr,0,<,pr1_mv2_obr  pr1_mv2_obr, ,<,pr1_mv3_obr
pr1_mv3_obr,1,<,pr1_mv3_obr  pr1_mv3_obr,0,<,pr1_mv3_obr  pr1_mv3_obr, ,1,pr1_1_next

pr1_1_next,1,>,opr1

# ПИШЕМ НУЛИК ( 0 )

pr1_mv1_0, ,>,pr1_mv2_2
pr1_mv2_2,1,>,pr1_mv2_2  pr1_mv2_2,0,>,pr1_mv2_2  pr1_mv2_2, ,>,pr1_mv3_2
pr1_mv3_2,1,>,pr1_mv3_2  pr1_mv3_2,0,>,pr1_mv3_2  pr1_mv3_2, ,>,pr1_mv4_2
pr1_mv4_2,1,>,pr1_mv4_2  pr1_mv4_2,0,>,pr1_mv4_2  pr1_mv4_2, ,0,pr1_mv1_obr_0

# ИДЕМ ОБРАТНО В НАЧАЛО ПЕРВОГО СЛОВА

pr1_mv1_obr_0,1,<,pr1_mv1_obr_0  pr1_mv1_obr_0,0,<,pr1_mv1_obr_0  pr1_mv1_obr_0, ,<,pr1_mv2_obr_0
pr1_mv2_obr_0,1,<,pr1_mv2_obr_0  pr1_mv2_obr_0,0,<,pr1_mv2_obr_0  pr1_mv2_obr_0, ,<,pr1_mv3_obr_0
pr1_mv3_obr_0,1,<,pr1_mv3_obr_0  pr1_mv3_obr_0,0,<,pr1_mv3_obr_0  pr1_mv3_obr_0, ,0,pr1_0_next

pr1_0_next,0,>,opr1

# КОПИРУЕМ ВТОРОЕ ЧИСЕЛКО ( 2 )
# определяем 1 или нулик

opr2,1, ,pr2_mv1_1  opr2,0, ,pr2_mv1_0 opr2, ,>,mv_to_fin1

#ПИШЕМ ЕДИНИЧКУ ( 1 )

pr2_mv1_1, ,>,pr2_mv2_1
pr2_mv2_1,1,>,pr2_mv2_1  pr2_mv2_1,0,>,pr2_mv2_1  pr2_mv2_1, ,>,pr2_mv3_1
pr2_mv3_1,1,>,pr2_mv3_1  pr2_mv3_1,0,>,pr2_mv3_1  pr2_mv3_1, ,>,pr2_mv4_1
pr2_mv4_1,1,>,pr2_mv4_1  pr2_mv4_1,0,>,pr2_mv4_1  pr2_mv4_1, ,1,pr2_mv1_obr

# ИДЕМ ОБРАТНО В НАЧАЛО ВТОРОГО СЛОВА

pr2_mv1_obr,1,<,pr2_mv1_obr  pr2_mv1_obr,0,<,pr2_mv1_obr  pr2_mv1_obr, ,<,pr2_mv2_obr
pr2_mv2_obr,1,<,pr2_mv2_obr  pr2_mv2_obr,0,<,pr2_mv2_obr  pr2_mv2_obr, ,<,pr2_mv3_obr
pr2_mv3_obr,1,<,pr2_mv3_obr  pr2_mv3_obr,0,<,pr2_mv3_obr  pr2_mv3_obr, ,1,pr2_1_next

pr2_1_next,1,>,opr2

# ПИШЕМ НУЛИК ( 0 )

pr2_mv1_0, ,>,pr2_mv2_2
pr2_mv2_2,1,>,pr2_mv2_2  pr2_mv2_2,0,>,pr2_mv2_2  pr2_mv2_2, ,>,pr2_mv3_2
pr2_mv3_2,1,>,pr2_mv3_2  pr2_mv3_2,0,>,pr2_mv3_2  pr2_mv3_2, ,>,pr2_mv4_2
pr2_mv4_2,1,>,pr2_mv4_2  pr2_mv4_2,0,>,pr2_mv4_2  pr2_mv4_2, ,0,pr2_mv1_obr_0

# ИДЕМ ОБРАТНО В НАЧАЛО ВТОРОГО СЛОВА

pr2_mv1_obr_0,1,<,pr2_mv1_obr_0  pr2_mv1_obr_0,0,<,pr2_mv1_obr_0  pr2_mv1_obr_0, ,<,pr2_mv2_obr_0
pr2_mv2_obr_0,1,<,pr2_mv2_obr_0  pr2_mv2_obr_0,0,<,pr2_mv2_obr_0  pr2_mv2_obr_0, ,<,pr2_mv3_obr_0
pr2_mv3_obr_0,1,<,pr2_mv3_obr_0  pr2_mv3_obr_0,0,<,pr2_mv3_obr_0  pr2_mv3_obr_0, ,0,pr2_0_next

pr2_0_next,0,>,opr2

mv_to_fin1,1,>,mv_to_fin1  mv_to_fin1,0,>,mv_to_fin1  mv_to_fin1, ,>,mv_to_fin2
mv_to_fin2,1,>,mv_to_fin2  mv_to_fin2,0,>,mv_to_fin2  mv_to_fin2, ,<,rmv1

//ОСНОВНОЙ КОД

#удаляем 1 из последнего числа и стираем его

rmv1,0,<,rmv1  rmv1,1,0,rmv2  rmv1, ,>,del1
rmv2,0,>,rmv3
rmv3,0,1,rmv3  rmv3,1,>,rmv3 rmv3, ,<,rmv_to_s_1st

#удаляем нолики

del1,0, ,del2  del1, ,<,move_to_fin
del2, ,>,del1

move_to_fin, ,<,move_to_fin  move_to_fin,1,>,fin  move_to_fin,0,>,fin
fin, ,#,fin

# ДЕЛАЕМ СДВИГ НА 1 ВПРАВО ПЕРВОГО ЧИСЛА ( СКОПИРОВАННОГО ) ( > ) !!! ОКАНЧИВАЕТСЯ НА ( rmv1 ) !!!

# двигаем к началу первого слова

rmv_to_s_1st,1,<,rmv_to_s_1st  rmv_to_s_1st,0,<,rmv_to_s_1st  rmv_to_s_1st, ,<,ars1



# !!! делаем арифм сдвиг на 1 вправо !!!

# удаляем ласт элемент

ars1,1, ,ars2  ars1,0, ,ars2
ars2, ,<,ars2  ars2,1, ,ars3_1  ars2,0, ,ars3_0

ars6,1, ,ars3_1  ars6,0, ,ars3_0  ars6, ,>,ars8

ars3_1, ,>,ars4_1
ars4_1, ,1,ars4_1  ars4_1,1,<,ars5

ars3_0, ,>,ars4_0
ars4_0, ,0,ars4_0  ars4_0,0,<,ars5

ars5, ,<,ars6

ars8, ,>,ars8  ars8,0,<,ars9  ars8,1,<,ars10
ars9, ,0,ret1
ars10, ,1,ret1

# возвращение каретки из начала первого числа в конец второго

ret1,1,>,ret1  ret1,0,>,ret1  ret1, ,>,ret2
ret2,1,>,ret2  ret2,0,>,ret2  ret2, ,<,rmv1
