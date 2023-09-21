// Решите поставленную задачу в формате четвёрок
00, ,*,c

c,*,<,c
c,i,<,c
c,o,<,c
c,1,i,l1
c,0,o,l0
c, ,=,Le

l0,0,<,l0
l0,1,<,l0
l0,o,<,l0
l0,i,<,l0
l0, ,>,c0

l1,0,<,l1
l1,1,<,l1
l1,o,<,l1
l1,i,<,l1
l1, ,>,c1

c0,0,o,r1
c0,o,>,c0
c0,1,i,r0
c0,i,>,c0
c0,*,=,r1

c1,0,o,r0
c1,o,>,c1
c1,1,i,r1
c1,i,>,c1
c1,*,=,r1

r0,0,>,r0
r0,o,>,r0
r0,1,>,r0
r0,i,>,r0
r0,*,>,w0

r1,0,>,r1
r1,o,>,r1
r1,1,>,r1
r1,i,>,r1
r1,*,>,w1

w1,0,=,Le
w1,1,=,h
w1, ,1,h

w0,0,=,Le
w0,1,0,Le
w0, ,0,Le

h,0,<,h
h,1,<,h
h,*,=,c

Le,0,<,Le
Le,o,<,Le
Le,1,<,Le
Le,i,<,Le
Le,*,<,Le
Le, ,>,end

end,0,>,end
end,o,0,re
end,1,>,end
end,i,1,re
end,*, ,re
end, ,#,end

re,0,>,end
re,1,>,end
re, ,>,end
