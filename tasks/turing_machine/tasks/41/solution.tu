/ Решите поставленную задачу в формате четвёрок
00, ,/,to/
to/,/,<,define  to/,0,<,to/  to/,1,<,to/ to/,2,<,to/  //двигаемся до символа, стоящего слева от /
define,0,),num0  define,1,!,num1  define,2,@,num2  define,),<,define  define,!,<,define  define,@,<,define  define, ,>,rep  //определение числа и его замена на соответствующий символ
num0,),>,num0  num0,!,>,num0  num0,@,>,num0  num0,0,>,num0  num0,1,>,num0  num0,2,>,num0  num0,/,>,num0  num0, ,0,to/  //копирование нуля
num1,),>,num1  num1,!,>,num1  num1,@,>,num1  num1,0,>,num1  num1,1,>,num1  num1,2,>,num1  num1,/,>,num1  num1, ,1,to/  //копирование единицы
num2,),>,num2  num2,!,>,num2  num2,@,>,num2  num2,0,>,num2  num2,1,>,num2  num2,2,>,num2  num2,/,>,num2  num2, ,2,to/  //копирование двойки
rep,),0,ri  rep,!,1,ri  rep,@,2,ri  rep,/, ,rep  rep, ,>,end  //обратная замена
ri,0,>,rep  ri,1,>,rep  ri,2,>,rep  //сдвиг вправо для обратной замены
end,0,>,end  end,1,>,end  end,2,>,end  end, ,#,end  //сдвиг в конец и полная остановка машины
