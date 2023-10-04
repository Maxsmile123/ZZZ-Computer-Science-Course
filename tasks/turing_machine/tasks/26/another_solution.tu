00, ,=,copy_l

// # Копирование слова

// 1. Идём ВЛЕВО и ставим тот знак, который запомнили, 
// 2. Шагаем вправо, запоминаем знак(если=" " сост.4) и 
//      идём ВПРАВОх2, записываем там знак
// 3. Идём ВЛЕВО и возвращаемся в состояние 1
// 4. Идём ВПРАВО.

copy_l, ,<,copy_L_l_1
copy_0, ,<,copy_L_0_1
copy_1, ,<,copy_L_1_1

copy_L_l_1, , ,rcopy_check
copy_L_l_1,0,<,copy_L_l_1
copy_L_l_1,1,<,copy_L_l_1
copy_L_0_1, ,0,rcopy_check
copy_L_0_1,0,<,copy_L_0_1
copy_L_0_1,1,<,copy_L_0_1
copy_L_1_1, ,1,rcopy_check
copy_L_1_1,0,<,copy_L_1_1
copy_L_1_1,1,<,copy_L_1_1

copy_L_0, , ,copy_check
copy_L_0,0,<,copy_L_0
copy_L_0,1,<,copy_L_0

copy_L_1, ,>,copy_check
copy_L_1,0,<,copy_L_1
copy_L_1,1,<,copy_L_1

rcopy_check, ,>,copy_check
rcopy_check,0,>,copy_check
rcopy_check,1,>,copy_check

copy_check, ,>,copy_R
copy_check,0, ,rcopy_R_0_1
copy_check,1, ,rcopy_R_1_1

rcopy_R_0_1, ,>,copy_R_0_1
rcopy_R_1_1, ,>,copy_R_1_1

copy_R_0_1, ,>,copy_R_0_2
copy_R_0_1,0,>,copy_R_0_1
copy_R_0_1,1,>,copy_R_0_1
copy_R_0_2, ,0,copy_L_0_2
copy_R_0_2,0,>,copy_R_0_2
copy_R_0_2,1,>,copy_R_0_2

copy_R_1_1, ,>,copy_R_1_2
copy_R_1_1,0,>,copy_R_1_1
copy_R_1_1,1,>,copy_R_1_1
copy_R_1_2, ,1,copy_L_1_2
copy_R_1_2,0,>,copy_R_1_2
copy_R_1_2,1,>,copy_R_1_2

copy_L_0_2, ,=,copy_0
copy_L_0_2,0,<,copy_L_0_2
copy_L_0_2,1,<,copy_L_0_2
copy_L_1_2, ,=,copy_1
copy_L_1_2,0,<,copy_L_1_2
copy_L_1_2,1,<,copy_L_1_2

copy_R, ,=,p_home // тут надо поменять на нужное состояние
copy_R,0,>,copy_R
copy_R,1,>,copy_R

// # Проверка на палиндромию

// 1. Идём влево и запоминаем знак, заменяем его на пробел
// 2. Идём влево
// 3. Идём ВЛЕВО, потом вправо, 
// 4. Проверяем совпал ли знак, меняем на пробел

// Если совпал:
// 5.1. Шаг вправо
// 5.2. Идём ВПРАВО, запускаем шаг 1.

// Если не совпало:
// 6.1. Шаг вправо
// 6.2. Идём ВПРАВО
// 6.3. Цикл: 1) Шаг влево
// 	      2) Заменить знак на пробел, запустить шаг 1)
// 6.4. 

// шаг 1.
p_home, ,<,p_check

p_check, ,<,p_LL_E1
p_check,0, ,p_lL_0
p_check,1, ,p_lL_1

// шаг 2.
p_lL_0, ,<,p_L_0
p_lL_1, ,<,p_L_1

// шаг 3.
p_L_0, ,>,p_check2_0
p_L_0,0,<,p_L_0
p_L_0,1,<,p_L_0

p_L_1, ,>,p_check2_1
p_L_1,0,<,p_L_1
p_L_1,1,<,p_L_1

// шаг 4.
p_check2_0, ,<,p_LL_E1
p_check2_0,0, ,p_rR
p_check2_0,1, ,p_rR_E0

p_check2_1, ,<,p_LL_E1
p_check2_1,0, ,p_rR_E0
p_check2_1,1, ,p_rR

// шаг 5.1.
p_rR, ,>,p_R

p_R, ,<,p_check
p_R,0,>,p_R
p_R,1,>,p_R

// шаг 6.1.
p_rR_E0, ,>,p_R_E0

p_R_E0, ,<,p_CL_E0
p_R_E0,0,>,p_R_E0
p_R_E0,1,>,p_R_E0

// шаг 6.2.
p_CL_E0, ,<,p_LL_E0 // изменить эту строку
p_CL_E0,0, ,p_lCL_E0
p_CL_E0,1, ,p_lCL_E0

p_lCL_E0, ,<,p_CL_E0

p_LL_E0, ,<,p_LL_E0
p_LL_E0,0,>,p_r_E0
p_LL_E0,1,>,p_r_E0

p_r_E0, ,>,p_W_E0

p_W_E0, ,0,p_rE0
p_rE0,0,>,p_E0
p_E0, ,#,p_E0

//
p_LL_E1, ,<,p_LL_E1
p_LL_E1,0,>,p_r_E1
p_LL_E1,1,>,p_r_E1

p_r_E1, ,>,p_W_E1

p_W_E1, ,1,p_rE1
p_rE1,1,>,p_E1
p_E1, ,#,p_E1
