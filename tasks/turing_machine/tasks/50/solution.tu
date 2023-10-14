// Решите поставленную задачу в формате четвёрок
//Идём в начало строки
00, ,<,01
01,0,<,01
01,1,<,01
01,2,<,01
01,3,<,01
01,4,<,01
01,5,<,01
01,6,<,01
01,7,<,01
01,8,<,01
01, ,>,02

//Затираем цифру
02,0, ,q0
02,1, ,q1
02,2, ,q2
02,3, ,q3
02,4, ,q4
02,5, ,q5
02,6, ,q6
02,7, ,q7
02,8, ,q8
02, ,>,zz0

//Идём в конец и проверяем первую цифру на 0
zz0,1,>,z
zz0,2,>,z
zz0,0, ,dvig
dvig, ,>,dvigg

//Если первая цифра 0, то двигаем всё число влево на 1
dvigg,0, ,dvig0
dvig0, ,<,dvig00
dvig00, ,0,dvig00
dvig00,0,>,dvig

dvigg,1, ,dvig1
dvig1, ,<,dvig11
dvig11, ,1,dvig11
dvig11,1,>,dvig

dvigg,2, ,dvig2
dvig2, ,<,dvig22
dvig22, ,2,dvig22
dvig22,2,>,dvig

//Завершаем программу
dvigg, ,<,end
end, ,#,end

//Идём в конец строки и завершаем программу
z,0,>,z
z,1,>,z
z,2,>,z
z, ,#,z
//Преодолеваем пробел
q0, ,>,zer
q1, ,>,one
q2, ,>,two
q3, ,>,tri
q4, ,>,for
q5, ,>,fiv
q6, ,>,six
q7, ,>,sev
q8, ,>,vos

//Движемся в конец
zer,0,>,zer
zer,1,>,zer
zer,2,>,zer
zer,3,>,zer
zer,4,>,zer
zer,5,>,zer
zer,6,>,zer
zer,7,>,zer
zer,8,>,zer
zer, ,>,go0

one,0,>,one
one,1,>,one
one,2,>,one
one,3,>,one
one,4,>,one
one,5,>,one
one,6,>,one
one,7,>,one
one,8,>,one
one, ,>,go1

two,0,>,two
two,1,>,two
two,2,>,two
two,3,>,two
two,4,>,two
two,5,>,two
two,6,>,two
two,7,>,two
two,8,>,two
two, ,>,go2

tri,0,>,tri
tri,1,>,tri
tri,2,>,tri
tri,3,>,tri
tri,4,>,tri
tri,5,>,tri
tri,6,>,tri
tri,7,>,tri
tri,8,>,tri
tri, ,>,go3

for,0,>,for
for,1,>,for
for,2,>,for
for,3,>,for
for,4,>,for
for,5,>,for
for,6,>,for
for,7,>,for
for,8,>,for
for, ,>,go4

fiv,0,>,fiv
fiv,1,>,fiv
fiv,2,>,fiv
fiv,3,>,fiv
fiv,4,>,fiv
fiv,5,>,fiv
fiv,6,>,fiv
fiv,7,>,fiv
fiv,8,>,fiv
fiv, ,>,go5

six,0,>,six
six,1,>,six
six,2,>,six
six,3,>,six
six,4,>,six
six,5,>,six
six,6,>,six
six,7,>,six
six,8,>,six
six, ,>,go6

sev,0,>,sev
sev,1,>,sev
sev,2,>,sev
sev,3,>,sev
sev,4,>,sev
sev,5,>,sev
sev,6,>,sev
sev,7,>,sev
sev,8,>,sev
sev, ,>,go7

vos,0,>,vos
vos,1,>,vos
vos,2,>,vos
vos,3,>,vos
vos,4,>,vos
vos,5,>,vos
vos,6,>,vos
vos,7,>,vos
vos,8,>,vos
vos, ,>,go8

//Движемся в конец и ставим цифру
go0,0,>,go0
go0,1,>,go0
go0,2,>,go0
go0, ,0,c0
c0,0,>,c0
c0, ,0,nach0

go1,0,>,go1
go1,1,>,go1
go1,2,>,go1
go1, ,0,c1
c1,0,>,c1
c1, ,1,nach1

go2,0,>,go2
go2,1,>,go2
go2,2,>,go2
go2, ,0,c2
c2,0,>,c2
c2, ,2,nach2

go3,0,>,go3
go3,1,>,go3
go3,2,>,go3
go3, ,1,c3
c3,1,>,c3
c3, ,0,nach3

go4,0,>,go4
go4,1,>,go4
go4,2,>,go4
go4, ,1,c4
c4,1,>,c4
c4, ,1,nach4

go5,0,>,go5
go5,1,>,go5
go5,2,>,go5
go5, ,1,c5
c5,1,>,c5
c5, ,2,nach5

go6,0,>,go6
go6,1,>,go6
go6,2,>,go6
go6, ,2,c6
c6,2,>,c6
c6, ,0,nach6

go7,0,>,go7
go7,1,>,go7
go7,2,>,go7
go7, ,2,c7
c7,2,>,c7
c7, ,1,nach7

go8,0,>,go8
go8,1,>,go8
go8,2,>,go8
go8, ,2,c8
c8,2,>,c8
c8, ,2,nach8


//Идём в начало строки
nach0,0,<,nach0
nach0,1,<,nach0
nach0,2,<,nach0
nach0, ,<,nach00

nach1,0,<,nach1
nach1,1,<,nach1
nach1,2,<,nach1
nach1, ,<,nach11

nach2,0,<,nach2
nach2,1,<,nach2
nach2,2,<,nach2
nach2, ,<,nach22

nach3,0,<,nach3
nach3,1,<,nach3
nach3,2,<,nach3
nach3, ,<,nach33

nach4,0,<,nach4
nach4,1,<,nach4
nach4,2,<,nach4
nach4, ,<,nach44

nach5,0,<,nach5
nach5,1,<,nach5
nach5,2,<,nach5
nach5, ,<,nach55

nach6,0,<,nach6
nach6,1,<,nach6
nach6,2,<,nach6
nach6, ,<,nach66

nach7,0,<,nach7
nach7,1,<,nach7
nach7,2,<,nach7
nach7, ,<,nach77

nach8,0,<,nach8
nach8,1,<,nach8
nach8,2,<,nach8
nach8, ,<,nach88

//Продолжаем идти в начало строки и возвращаем цифру на место
nach00,0,<,nach00
nach00,1,<,nach00
nach00,2,<,nach00
nach00,3,<,nach00
nach00,4,<,nach00
nach00,5,<,nach00
nach00,6,<,nach00
nach00,7,<,nach00
nach00,8,<,nach00
nach00, ,0,new0

nach11,0,<,nach11
nach11,1,<,nach11
nach11,2,<,nach11
nach11,3,<,nach11
nach11,4,<,nach11
nach11,5,<,nach11
nach11,6,<,nach11
nach11,7,<,nach11
nach11,8,<,nach11
nach11, ,1,new1

nach22,0,<,nach22
nach22,1,<,nach22
nach22,2,<,nach22
nach22,3,<,nach22
nach22,4,<,nach22
nach22,5,<,nach22
nach22,6,<,nach22
nach22,7,<,nach22
nach22,8,<,nach22
nach22, ,2,new2

nach33,0,<,nach33
nach33,1,<,nach33
nach33,2,<,nach33
nach33,3,<,nach33
nach33,4,<,nach33
nach33,5,<,nach33
nach33,6,<,nach33
nach33,7,<,nach33
nach33,8,<,nach33
nach33, ,3,new3

nach44,0,<,nach44
nach44,1,<,nach44
nach44,2,<,nach44
nach44,3,<,nach44
nach44,4,<,nach44
nach44,5,<,nach44
nach44,6,<,nach44
nach44,7,<,nach44
nach44,8,<,nach44
nach44, ,4,new4

nach55,0,<,nach55
nach55,1,<,nach55
nach55,2,<,nach55
nach55,3,<,nach55
nach55,4,<,nach55
nach55,5,<,nach55
nach55,6,<,nach55
nach55,7,<,nach55
nach55,8,<,nach55
nach55, ,5,new5

nach66,0,<,nach66
nach66,1,<,nach66
nach66,2,<,nach66
nach66,3,<,nach66
nach66,4,<,nach66
nach66,5,<,nach66
nach66,6,<,nach66
nach66,7,<,nach66
nach66,8,<,nach66
nach66, ,6,new6

nach77,0,<,nach77
nach77,1,<,nach77
nach77,2,<,nach77
nach77,3,<,nach77
nach77,4,<,nach77
nach77,5,<,nach77
nach77,6,<,nach77
nach77,7,<,nach77
nach77,8,<,nach77
nach77, ,7,new7

nach88,0,<,nach88
nach88,1,<,nach88
nach88,2,<,nach88
nach88,3,<,nach88
nach88,4,<,nach88
nach88,5,<,nach88
nach88,6,<,nach88
nach88,7,<,nach88
nach88,8,<,nach88
nach88, ,8,new8

//Переходим к следующей цифре
new0,0,>,02
new1,1,>,02
new2,2,>,02
new3,3,>,02
new4,4,>,02
new5,5,>,02
new6,6,>,02
new7,7,>,02
new8,8,>,02
