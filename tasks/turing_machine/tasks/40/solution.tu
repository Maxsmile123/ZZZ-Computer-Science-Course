00, ,<,l3

#Убираем ведущие нули и добавляем минус, если необходимо
l3,-,<,l3
l3,0,<,l3
l3,1,<,l3
l3,2,<,l3
l3,m,<,l3
l3, ,>,z1

l1,m,<,l1
l1,n,<,l1
l1,o,<,l1
l1,d,<,l1
l1,-,<,l1
l1,0,<,l1
l1,1,<,l1
l1,2,<,l1
l1, ,>,zz

z1,-,m,zmp2
z1,m,>,z1
z1,0,n,z1
z1,n,>,z1
z1, ,>,z1n
z1,1,=,zz
z1,2,=,zz

z1n,-,0,z1n
z1n, ,0,z1n
z1n,0,<,z1nn
z1nn, ,<,v1

zmp2,m,>,zmp2
zmp2,0,>,zmp2
zmp2,1,>,zmp2
zmp2,2,>,zmp2
zmp2, ,>,zmpp2

zmpp2,0,>,zmpp2
zmpp2,1,>,zmpp2
zmpp2,2,>,zmpp2
zmpp2, ,-,zmpp2
zmpp2,-,<,00

#Влево по исходному числу
zz,m,>,zz
zz,n,>,zz
zz,o,>,zz
zz,d,>,zz
zz,0,n,z0p
zz,1,o,z1p
zz,2,d,z2p
zz, ,<,v1

#Копируем исходное число
zmp,m,>,zmp
zmp,n,>,zmp
zmp,o,>,zmp
zmp,d,>,zmp
zmp,0,>,zmp
zmp,1,>,zmp
zmp,2,>,zmp
zmp, ,>,zmpp

zmpp,-,>,zmpp
zmpp,0,>,zmpp
zmpp,1,>,zmpp
zmpp,2,>,zmpp
zmpp, ,-,l2

z0p,m,>,z0p
z0p,n,>,z0p
z0p,o,>,z0p
z0p,d,>,z0p
z0p,-,>,z0p
z0p,0,>,z0p
z0p,1,>,z0p
z0p,2,>,z0p
z0p, ,>,z0pp

z0pp,-,>,z0pp
z0pp,0,>,z0pp
z0pp,1,>,z0pp
z0pp,2,>,z0pp
z0pp, ,0,l2

z1p,m,>,z1p
z1p,n,>,z1p
z1p,o,>,z1p
z1p,d,>,z1p
z1p,-,>,z1p
z1p,0,>,z1p
z1p,1,>,z1p
z1p,2,>,z1p
z1p, ,>,z1pp

z1pp,-,>,z1pp
z1pp,0,>,z1pp
z1pp,1,>,z1pp
z1pp,2,>,z1pp
z1pp, ,1,l2

z2p,m,>,z2p
z2p,n,>,z2p
z2p,o,>,z2p
z2p,d,>,z2p
z2p,-,>,z2p
z2p,0,>,z2p
z2p,1,>,z2p
z2p,2,>,z2p
z2p, ,>,z2pp

z2pp,-,>,z2pp
z2pp,0,>,z2pp
z2pp,1,>,z2pp
z2pp,2,>,z2pp
z2pp, ,2,l2

#Возвращаем исходное число
v1,m,-,v1
v1,n,0,v1
v1,o,1,v1
v1,d,2,v1
v1,-,<,v1
v1,0,<,v1
v1,1,<,v1
v1,2,<,v1
v1, ,>,pp

l2,-,<,l2
l2,0,<,l2
l2,1,<,l2
l2,2,<,l2
l2, ,<,l1

pp,-,>,pp
pp,0,>,pp
pp,1,>,pp
pp,2,>,pp
pp, ,>,p3

#Двигаем головку вправо
p3,-,>,p3
p3,0,>,p3
p3,1,>,p3
p3,2,>,p3
p3, ,#,p3
