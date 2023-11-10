// Решите поставленную задачу в формате четвёрок
00, ,A,01
01,A,<,ch1
// Заменяем 1 на f, 0 на z, записываем решение после A в обратном порядке
ch1,1,f,11w1
ch1,0,z,10w1

10w1,1,<,10w1
10w1,0,<,10w1
10w1,f,<,10w1
10w1,z,<,10w1
10w1,&,<,10w2

10w2,1,f,p0
10w2,0,z,p0
10w2,f,<,10w2
10w2,z,<,10w2


11w1,1,<,11w1
11w1,0,<,11w1
11w1,f,<,11w1
11w1,z,<,11w1
11w1,&,<,11w2

11w2,1,f,p1
11w2,0,z,p0
11w2,f,<,11w2
11w2,z,<,11w2

p0,1,>,p0
p0,0,>,p0
p0,&,>,p0
p0,f,>,p0
p0,z,>,p0
p0,A,>,p0A

p0A, ,0,to_back
p0A,1,>,p0A
p0A,0,>,p0A

p1,1,>,p1
p1,0,>,p1
p1,&,>,p1
p1,f,>,p1
p1,z,>,p1
p1,A,>,p1A

p1A, ,1,to_back
p1A,1,>,p1A
p1A,0,>,p1A

to_back,1,<,to_back
to_back,0,<,to_back
to_back,f,<,to_back
to_back,z,<,to_back
to_back,A,=,back

back,A,<,back
back,f,<,back
back,z,<,back
back,1,=,ch1
back,0,=,ch1
back,&,<,st2

//Перезаписывем решение в прямом порядке и приводим ленту в нормальный вид

st2,f,<,st2
st2,z,<,st2
st2,0,z,p0
st2,1,f,p1
st2, ,>,st3

st3,f,1,st3
st3,z,0,st3
st3,&,>,st3
st3,1,>,st3
st3,0,>,st3
st3,A,>,cp

cp,1,f,kcp1
cp,0,f,kcp0
cp, ,f,st5

kcp1,f,>,cp1
kcp0,f,>,cp0

cp1,1,>,cp1
cp1,0,>,cp1
cp1, ,>,mv1
cp1,f,>,cp1

mv1,1,>,mv1
mv1,0,>,mv1
mv1, ,=,cpp1

mv2,1,>,mv2
mv2,0,>,mv2
mv2, ,=,cpp0

cpp1, ,1,cpp1
cpp1,1,<,back2

cp0,1,>,cp0
cp0,0,>,cp0
cp0,f,>,cp0
cp0, ,>,mv2

cpp0, ,0,cpp0
cpp0,0,=,back2
cpp0,1,>,back2


back2,1,<,back2
back2,0,<,back2
back2, ,<,back2
back2,f,>,cp

st5,f,>,st5
st5,1,>,st5
st5,0,>,st5
st5, ,<,cop

cop,0, ,cop0
cop,1, ,cop1
cop,f, ,mv_l

cop0,1,<,cop0
cop0,0,<,cop0
cop0, ,<,cop0
cop0,f,<,cop0
cop0,A,>,pr0

cop1,1,<,cop1
cop1, ,<,cop1
cop1,0,<,cop1
cop1,f,<,cop1
cop1,A,>,pr1

pr0,f,0,st5
pr0,1,>,pr0
pr0,0,>,pr0
pr1,f,1,st5
pr1,0,>,pr1
pr1,1,>,pr1

mv_l, ,<,end
end,1,<,end
end,0,<,end
end,A, ,mv_r

mv_r, ,>,fin
fin,1,>,fin
fin,0,>,fin
fin, ,#,fin
