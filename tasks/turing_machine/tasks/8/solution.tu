// Решите поставленную задачу в формате четвёрок
00, ,<,first
first,0,<,zero   first,1,<,one
zero,0,<,first   zero,1,0,right   zero, ,>,fin
one,1,<,first   one,0,1,right   one, ,>,fin
right,0,>,swap   right,1,>,swap
swap,1,0,left2   swap,0,1,left2
left2,1,<,left   left2,0,<,left
left,1,<,first   left,0,<,first
fin,0,>,fin   fin,1,>,fin   fin, ,#,fin
