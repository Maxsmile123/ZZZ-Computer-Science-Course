// Решите поставленную задачу в формате четвёрок
//начальное состояние - пробел после 2ого числа, сдвигаемся влево и ищем элемент, который будем копировать
00, ,<,start_number2
start_number2,0,<,start_number2
start_number2,1,<,start_number2
start_number2,2,<,start_number2
start_number2,3,<,start_number2
start_number2, ,<,start_number1
//нашли пробел перед 2ым числом, сдвигаемся влево и ищем начало 1ого числа
start_number1,0,<,start_number1 
start_number1,1,<,start_number1 
start_number1,2,0,interim
interim,0,>,find_copy_number1
interim,1,>,find_copy_number1
start_number1,3,1,interim 
start_number1, ,>,find_copy_number1
find_copy_number1, ,>,find_beggin_2nd
find_beggin_2nd,0,>,find_beggin_2nd
find_beggin_2nd,1,>,find_beggin_2nd
find_beggin_2nd, ,<,back_to_2nd_1
find_beggin_2nd,3,1,find_end
find_beggin_2nd,2,0,find_end
find_end,0,>,find_end
find_end,1,>,find_end
find_end, ,>,end_3rd_find
//находим конец полученного числа
end_3rd_find,0,>,end_3rd_find
end_3rd_find,1,>,end_3rd_find
end_3rd_find, ,=,end

//находим символ, который можем скопировать (0), заменяем его служебным символом (2)
find_copy_number1,0,2,move_0_to_3rd
//находим конец 1ого числа
move_0_to_3rd,0,>,move_0_to_3rd
move_0_to_3rd,1,>,move_0_to_3rd
move_0_to_3rd,2,>,move_0_to_3rd
move_0_to_3rd,3,>,move_0_to_3rd
move_0_to_3rd, ,>,pass_0_to_3rd
//нашли конец 1ого числа, находим конец 2ого числа
pass_0_to_3rd,0,>,pass_0_to_3rd
pass_0_to_3rd,1,>,pass_0_to_3rd
pass_0_to_3rd,2,>,pass_0_to_3rd
pass_0_to_3rd,3,>,pass_0_to_3rd
pass_0_to_3rd, ,>,send_0_to_3rd
//нашли конец 2ого числа, находим конец 3его числа
send_0_to_3rd,0,>,send_0_to_3rd
send_0_to_3rd,1,>,send_0_to_3rd
//нашли конец 3его числа, записали (0), ищем начало 3его числа
send_0_to_3rd, ,0,back_to_3rd_0


//находим символ, который можем скопировать (1), заменяем его служебным символом (3)
find_copy_number1,1,3,move_1_to_3rd
//находим конец 1ого числа
move_1_to_3rd,0,>,move_1_to_3rd
move_1_to_3rd,1,>,move_1_to_3rd
move_1_to_3rd,2,>,move_1_to_3rd
move_1_to_3rd,3,>,move_1_to_3rd
move_1_to_3rd, ,>,pass_1_to_3rd
//нашли конец 1ого числа, находим конец 2ого числа
pass_1_to_3rd,0,>,pass_1_to_3rd
pass_1_to_3rd,1,>,pass_1_to_3rd
pass_1_to_3rd,2,>,pass_1_to_3rd
pass_1_to_3rd,3,>,pass_1_to_3rd
pass_1_to_3rd, ,>,send_1_to_3rd
//нашли конец 2ого числа, находим конец 3его числа
send_1_to_3rd,0,>,send_1_to_3rd
send_1_to_3rd,1,>,send_1_to_3rd
//нашли конец 3его числа, записали (1) ищем начало 3его числа
send_1_to_3rd, ,1,back_to_3rd_1


//после того, как записали (0) к 3ему числу ищем его начало
back_to_3rd_0,0,<,back_to_3rd_0
back_to_3rd_0,1,<,back_to_3rd_0
back_to_3rd_0, ,<,back_to_2nd_0
//нашли начало 3его числа, находим элемент из 2ого числа, который можно заменить служебным символом
back_to_2nd_0,0,<,back_to_2nd_0
back_to_2nd_0,1,<,back_to_2nd_0
back_to_2nd_0,2,0,interim_2
interim_2,0,>,rewrite_2nd_0
interim_2,1,>,rewrite_2nd_0
back_to_2nd_0,3,1,interim_2
back_to_2nd_0, ,>,rewrite_2nd_0
//нашли (0), заменяем его служебным символом (2)
rewrite_2nd_0,0,2,find_end_2nd
//нашли (1), заменяем его служебным символом (3)
rewrite_2nd_0,1,3,change_3rd_0_to_1
change_3rd_0_to_1,0,>,change_3rd_0_to_1
change_3rd_0_to_1,1,>,change_3rd_0_to_1
change_3rd_0_to_1,2,>,change_3rd_0_to_1
change_3rd_0_to_1,3,>,change_3rd_0_to_1
change_3rd_0_to_1, ,>,do_3rd_0_to_1
//нашли конец 2ого числа, ищем последний символ (0) 3его
do_3rd_0_to_1,0,>,do_3rd_0_to_1
do_3rd_0_to_1,1,>,do_3rd_0_to_1
do_3rd_0_to_1, ,<,rewrite_3rd_0_to_1
//нашли последний символ (0) 3его числа, заменим его на (1)
rewrite_3rd_0_to_1,0,1,find_begin_3rd
//находим начало 3его числа
find_begin_3rd,0,<,find_begin_3rd
find_begin_3rd,1,<,find_begin_3rd
find_begin_3rd, ,=,00


//находим конец 2ого числа
find_end_2nd,0,>,find_end_2nd
find_end_2nd,1,>,find_end_2nd
find_end_2nd,2,>,find_end_2nd
find_end_2nd,3,>,find_end_2nd
find_end_2nd, ,=,00


//после того, как записали (1) к 3ему числу ищем его начало
back_to_3rd_1,0,<,back_to_3rd_1
back_to_3rd_1,1,<,back_to_3rd_1
back_to_3rd_1, ,<,back_to_2nd_1
//нашли начало 3его числа, находим элемент из 2ого числа, который можно заменить служебным символом
back_to_2nd_1,0,<,back_to_2nd_1
back_to_2nd_1,1,<,back_to_2nd_1
back_to_2nd_1,2,0,interim_3
interim_3,0,>,rewrite_2nd_1
interim_3,1,>,rewrite_2nd_1
back_to_2nd_1,3,1,interim_3
back_to_2nd_1, ,>,rewrite_2nd_1


//нашли (0) заменяем его служебным символом (2)
rewrite_2nd_1,0,2,find_end_2nd
//нашли (1), заменяем его служебным символом (3)
rewrite_2nd_1,1,3,find_end_2nd

end,0,#,end
end,1,#,end
end,2,#,end
end,3,#,end
end, ,#,end
