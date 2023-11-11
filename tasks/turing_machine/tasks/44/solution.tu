# Влево до числа
00, ,<,01


// КОПИРОВАНИЕ

# Проход до начала числа

01,0,<,01  
01,1,<,01
01,2,<,01
01,3,<,01  
01,4,<,01
01,5,<,01
01,6,<,01
01,7,<,01
01, ,>,02

# Какое число

02,0, ,p000
02,1, ,p001
02,2, ,p010
02,3, ,p011
02,4, ,p100
02,5, ,p101
02,6, ,p110
02,7, ,p111
02, ,=,del0

#0

p000, ,>,p0002

p0002,0,>,p0002
p0002,1,>,p0002
p0002,2,>,p0002
p0002,3,>,p0002
p0002,4,>,p0002
p0002,5,>,p0002
p0002,6,>,p0002
p0002,7,>,p0002
p0002, ,>,p0003

p0003,0,>,p0003
p0003,1,>,p0003
p0003,2,>,p0003
p0003,3,>,p0003
p0003,4,>,p0003
p0003,5,>,p0003
p0003,6,>,p0003
p0003,7,>,p0003
p0003, ,0,p00030
p00030,0,>,p00030
p00030, ,0,p000300
p000300,0,>,p000300
p000300, ,0,back0

#1

p001, ,>,p0012

p0012,0,>,p0012
p0012,1,>,p0012
p0012,2,>,p0012
p0012,3,>,p0012
p0012,4,>,p0012
p0012,5,>,p0012
p0012,6,>,p0012
p0012,7,>,p0012
p0012, ,>,p0013

p0013,0,>,p0013
p0013,1,>,p0013
p0013,2,>,p0013
p0013,3,>,p0013
p0013,4,>,p0013
p0013,5,>,p0013
p0013,6,>,p0013
p0013,7,>,p0013
p0013, ,0,p00130
p00130,0,>,p00130
p00130, ,0,p001300
p001300,0,>,p001300
p001300, ,1,back1

#2

p010, ,>,p0102

p0102,0,>,p0102
p0102,1,>,p0102
p0102,2,>,p0102
p0102,3,>,p0102
p0102,4,>,p0102
p0102,5,>,p0102
p0102,6,>,p0102
p0102,7,>,p0102
p0102, ,>,p0103

p0103,0,>,p0103
p0103,1,>,p0103
p0103,2,>,p0103
p0103,3,>,p0103
p0103,4,>,p0103
p0103,5,>,p0103
p0103,6,>,p0103
p0103,7,>,p0103
p0103, ,0,p01030
p01030,0,>,p01030
p01030, ,1,p010300
p010300,1,>,p010300
p010300, ,0,back2

#3

p011, ,>,p0112

p0112,0,>,p0112
p0112,1,>,p0112
p0112,2,>,p0112
p0112,3,>,p0112
p0112,4,>,p0112
p0112,5,>,p0112
p0112,6,>,p0112
p0112,7,>,p0112
p0112, ,>,p0113

p0113,0,>,p0113
p0113,1,>,p0113
p0113,2,>,p0113
p0113,3,>,p0113
p0113,4,>,p0113
p0113,5,>,p0113
p0113,6,>,p0113
p0113,7,>,p0113
p0113, ,0,p01130
p01130,0,>,p01130
p01130, ,1,p011300
p011300,1,>,p011300
p011300, ,1,back3

#4

p100, ,>,p1002

p1002,0,>,p1002
p1002,1,>,p1002
p1002,2,>,p1002
p1002,3,>,p1002
p1002,4,>,p1002
p1002,5,>,p1002
p1002,6,>,p1002
p1002,7,>,p1002
p1002, ,>,p1003

p1003,0,>,p1003
p1003,1,>,p1003
p1003,2,>,p1003
p1003,3,>,p1003
p1003,4,>,p1003
p1003,5,>,p1003
p1003,6,>,p1003
p1003,7,>,p1003
p1003, ,1,p10030
p10030,1,>,p10030
p10030, ,0,p100300
p100300,0,>,p100300
p100300, ,0,back4

#5

p101, ,>,p1012

p1012,0,>,p1012
p1012,1,>,p1012
p1012,2,>,p1012
p1012,3,>,p1012
p1012,4,>,p1012
p1012,5,>,p1012
p1012,6,>,p1012
p1012,7,>,p1012
p1012, ,>,p1013

p1013,0,>,p1013
p1013,1,>,p1013
p1013,2,>,p1013
p1013,3,>,p1013
p1013,4,>,p1013
p1013,5,>,p1013
p1013,6,>,p1013
p1013,7,>,p1013
p1013, ,1,p10130
p10130,1,>,p10130
p10130, ,0,p101300
p101300,0,>,p101300
p101300, ,1,back5

#6

p110, ,>,p1102

p1102,0,>,p1102
p1102,1,>,p1102
p1102,2,>,p1102
p1102,3,>,p1102
p1102,4,>,p1102
p1102,5,>,p1102
p1102,6,>,p1102
p1102,7,>,p1102
p1102, ,>,p1103

p1103,0,>,p1103
p1103,1,>,p1103
p1103,2,>,p1103
p1103,3,>,p1103
p1103,4,>,p1103
p1103,5,>,p1103
p1103,6,>,p1103
p1103,7,>,p1103
p1103, ,1,p11030
p11030,1,>,p11030
p11030, ,1,p110300
p110300,1,>,p110300
p110300, ,0,back6

#7

p111, ,>,p1112

p1112,0,>,p1112
p1112,1,>,p1112
p1112,2,>,p1112
p1112,3,>,p1112
p1112,4,>,p1112
p1112,5,>,p1112
p1112,6,>,p1112
p1112,7,>,p1112
p1112, ,>,p1113

p1113,0,>,p1113
p1113,1,>,p1113
p1113,2,>,p1113
p1113,3,>,p1113
p1113,4,>,p1113
p1113,5,>,p1113
p1113,6,>,p1113
p1113,7,>,p1113
p1113, ,1,p11130
p11130,1,>,p11130
p11130, ,1,p111300
p111300,1,>,p111300
p111300, ,1,back7

#back0

back0,0,<,back0
back0,1,<,back0
back0,2,<,back0
back0,3,<,back0
back0,4,<,back0
back0,5,<,back0
back0,6,<,back0
back0,7,<,back0
back0, ,<,back02

back02,0,<,back02
back02,1,<,back02
back02,2,<,back02
back02,3,<,back02
back02,4,<,back02
back02,5,<,back02
back02,6,<,back02
back02,7,<,back02
back02, ,0,back03
back03,0,>,02

#back1

back1,0,<,back1
back1,1,<,back1
back1,2,<,back1
back1,3,<,back1
back1,4,<,back1
back1,5,<,back1
back1,6,<,back1
back1,7,<,back1
back1, ,<,back12

back12,0,<,back12
back12,1,<,back12
back12,2,<,back12
back12,3,<,back12
back12,4,<,back12
back12,5,<,back12
back12,6,<,back12
back12,7,<,back12
back12, ,1,back13
back13,1,>,02

#back2

back2,0,<,back2
back2,1,<,back2
back2,2,<,back2
back2,3,<,back2
back2,4,<,back2
back2,5,<,back2
back2,6,<,back2
back2,7,<,back2
back2, ,<,back22

back22,0,<,back22
back22,1,<,back22
back22,2,<,back22
back22,3,<,back22
back22,4,<,back22
back22,5,<,back22
back22,6,<,back22
back22,7,<,back22
back22, ,2,back23
back23,2,>,02

#back3

back3,0,<,back3
back3,1,<,back3
back3,2,<,back3
back3,3,<,back3
back3,4,<,back3
back3,5,<,back3
back3,6,<,back3
back3,7,<,back3
back3, ,<,back32

back32,0,<,back32
back32,1,<,back32
back32,2,<,back32
back32,3,<,back32
back32,4,<,back32
back32,5,<,back32
back32,6,<,back32
back32,7,<,back32
back32, ,3,back33
back33,3,>,02

#back4

back4,0,<,back4
back4,1,<,back4
back4,2,<,back4
back4,3,<,back4
back4,4,<,back4
back4,5,<,back4
back4,6,<,back4
back4,7,<,back4
back4, ,<,back42

back42,0,<,back42
back42,1,<,back42
back42,2,<,back42
back42,3,<,back42
back42,4,<,back42
back42,5,<,back42
back42,6,<,back42
back42,7,<,back42
back42, ,4,back43
back43,4,>,02

#back5

back5,0,<,back5
back5,1,<,back5
back5,2,<,back5
back5,3,<,back5
back5,4,<,back5
back5,5,<,back5
back5,6,<,back5
back5,7,<,back5
back5, ,<,back52

back52,0,<,back52
back52,1,<,back52
back52,2,<,back52
back52,3,<,back52
back52,4,<,back52
back52,5,<,back52
back52,6,<,back52
back52,7,<,back52
back52, ,5,back53
back53,5,>,02

#back6

back6,0,<,back6
back6,1,<,back6
back6,2,<,back6
back6,3,<,back6
back6,4,<,back6
back6,5,<,back6
back6,6,<,back6
back6,7,<,back6
back6, ,<,back62

back62,0,<,back62
back62,1,<,back62
back62,2,<,back62
back62,3,<,back62
back62,4,<,back62
back62,5,<,back62
back62,6,<,back62
back62,7,<,back62
back62, ,6,back63
back63,6,>,02

#back7

back7,0,<,back7
back7,1,<,back7
back7,2,<,back7
back7,3,<,back7
back7,4,<,back7
back7,5,<,back7
back7,6,<,back7
back7,7,<,back7
back7, ,<,back72

back72,0,<,back72
back72,1,<,back72
back72,2,<,back72
back72,3,<,back72
back72,4,<,back72
back72,5,<,back72
back72,6,<,back72
back72,7,<,back72
back72, ,7,back73
back73,7,>,02

#del0

del0, ,>,del0
del0,1,=,not0
del0,0,>,delchecknext
delchecknext,0,<,delpriv
delchecknext,1,<,delpriv
delpriv,0, ,delpriv
delpriv, ,>,del0
delchecknext, ,=,ans0

#ans0

ans0, ,<,ans0
ans0,0, ,set0
set0, ,<,set0
set0,0,>,set01
set0,1,>,set01
set0,2,>,set01
set0,3,>,set01
set0,4,>,set01
set0,5,>,set01
set0,6,>,set01
set0,7,>,set01
set01, ,>,pr0
pr0, ,0,left

#ansnot0

not0,1, ,checknext
checknext, ,>,checknext1
checknext1, ,<,end1
checknext1,0,<,noend
checknext1,1,<,noend
end1, ,<,end1
end1,0,>,end10
end1,1,>,end10
end1,2,>,end10
end1,3,>,end10
end1,4,>,end10
end1,5,>,end10
end1,6,>,end10
end1,7,>,end10
end10, ,>,end101
end101, ,1,left

#noend

noend, ,<,noend
noend,0,>,noend1
noend,1,>,noend1
noend,2,>,noend1
noend,3,>,noend1
noend,4,>,noend1
noend,5,>,noend1
noend,6,>,noend1
noend,7,>,noend1
noend1, ,>,noend10
noend10, ,1,backtoans

#backtoans

backtoans,1,>,backtoans1
backtoans,0,>,backtoans1
backtoans1, ,>,backtoans1
backtoans1,1,=,checktof
backtoans1,0,=,checktof

#checktof

checktof,0, ,checknextnf0
checktof,1, ,checknextnf1
checknextnf0, ,>,checknextnf00
checknextnf00, ,<,nowend0
checknextnf00,0,<,nownotend0
checknextnf00,1,<,nownotend0
nownotend0,0,<,nownotend01
nownotend0,1,<,nownotend01
nownotend0, ,<,nownotend01
nownotend01, ,<,nownotend01
nownotend01,0,>,pass0
nownotend01,1,>,pass0
pass0, ,0,nexttoans
nexttoans,0,>,nexttoans1
nexttoans,1,>,nexttoans1
nexttoans1, ,=,backtoans1
nexttoans1,1,=,checktof
nexttoans1,0,=,checktof
nowend0, ,<,nowend0
nowend0,0,>,pass0e
nowend0,1,>,pass0e
pass0e, ,0,left

checknextnf1, ,>,checknextnf10
checknextnf10, ,<,nowend1
checknextnf10,0,<,nownotend1
checknextnf10,1,<,nownotend1
nownotend1,0,<,nownotend10
nownotend1,1,<,nownotend10
nownotend1, ,<,nownotend10
nownotend10, ,<,nownotend10
nownotend10,0,>,pass1
nownotend10,1,>,pass1
pass1, ,1,nexttoans
nowend1, ,<,nowend1
nowend1,0,>,pass1e
nowend1,1,>,pass1e
pass1e, ,1,left

#fin

left, ,<,left
left,0,>,fin
left,1,>,fin
fin,0,>,fin
fin,1,>,fin
fin, ,#,fin
