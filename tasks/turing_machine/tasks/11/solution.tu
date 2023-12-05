00, ,<,num
num,0,<,if0 num,1,<,if1 num, ,#,num #чекаем символ в текущей строке

if0,0,0,next if0,1,0,goback1 if0, ,#,num #чекаем если число в след строке равно предыдущему и заменяем в противном
if1,1,1,next if1,0,1,goback0 if1, ,#,num

goback0,1,>,replaceon0
replaceon0,1,0,return

goback1,0,>,replaceon1
replaceon1,0,1,return

return,0,<,next return,1,<,next

next,1,<,num next,0,<,num

#это вариант 8
