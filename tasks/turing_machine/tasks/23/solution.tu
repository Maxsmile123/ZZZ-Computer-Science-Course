// Решите поставленную задачу в формате четвёрок
// begin

00, ,<,01

// move

01,|,<,skip
01,1,<,docopy
zero, ,>,placezero
placezero, ,|,end
docopy,|,<,docopy
docopy, ,<,skip6
docopy1,1,>,docopy1
docopy1,|,>,docopy1
docopy1, ,>,docopy2
docopy2,|,>,docopy2
docopy2,1,>,docopy2
docopy2, ,>,check
check,|,>,check
check, ,=,setval
setval, ,|,back
back,|,<,back
back, ,<,skip2

// skip first |

skip,|,=,chval
skip, ,>,skip1
skip,1,<,skip
skip1,|,>,zero

// skip values

skip2,|,<,skip2
skip2,1,<,skip2
skip2, ,<,skip6
skip3,1,<,skip3
skip3,|,=,chval1
skip3, ,>,clear
skip4,1,>,skip4
skip4,|,>,skip4
skip4, ,=,docopy1
skip5,|,>,skip5
skip5,1,>,skip5
skip5, ,=,00
skip6,|,<,chval1

// changing used values

chval,|,1,01
chval1,|,1,docopy1
chval1,1,<,chval1
chval1, ,>,clear
clear,1,|,clear
clear,|,>,clear
clear, ,>,checkend
checkend,|,=,skip5
checkend,1,=,clear2
clear2,1,|,clear2
clear2,|,>,clear2
clear2, ,>,add1
add1,|,>,add1
add1, ,|,end
end,|,>,end
end, ,#,end
