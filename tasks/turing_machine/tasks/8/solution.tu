// Решите поставленную задачу в формате четвёрок
00,1,<,left
00,0,<,left
00, ,<,left
left,0,<,left
left,1,<,left
left, ,>,check
left,2,0,fix
left,3,1,fix
fix,1,>,check
fix,0,>,check
check,0,>,zero
check,1,>,one
check, ,>,end
zero,0,2,oomv
zero,1,3,oimv
one,1,3,iimv
one,0,2,iomv

oomv,2,>,oo
oomv,3,>,oo
oimv,2,>,oi
oimv,3,>,oi
iimv,2,>,ii
iimv,3,>,ii
iomv,2,>,io
iomv,3,>,io

oo,1,>,oo
oo,0,>,oo
oo, ,>,ooi
ooi, ,0,oz
ooi,0,>,ooi
ooi,1,>,ooi

oi,1,>,oi
oi,0,>,oi
oi, ,>,oii
oii, ,1,oz
oii,0,>,oii
oii,1,>,oii

io,1,>,io
io,0,>,io
io, ,>,ioi
ioi, ,0,iz
ioi,0,>,ioi
ioi,1,>,ioi

ii,1,>,ii
ii,0,>,ii
ii, ,>,iii
iii, ,1,iz
iii,0,>,iii
iii,1,>,iii

iz,1,>,iz
iz,0,>,iz
iz, ,1,lef

oz,1,>,oz
oz,0,>,oz
oz, ,0,lef

lef,1,<,lef
lef,0,<,lef
lef, ,<,left

end, ,#,end
end,1,>,end
end,0,>,end
