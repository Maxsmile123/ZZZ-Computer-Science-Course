// Решите поставленную задачу в формате четвёрок


//mov - проехать в начало входного слова и встать на первую букву
//copy - запомнить цифру, на которой стоишь
//copy[0-8]_ - четверки moment (поставить пробел и съехать направо)
//movr[0-8] - ехать по входному направо
//movr[0-8]_ - ехать по выходному слову направо
//write[0-8] - написать первую букву из правого столбца таблицы "быстрого перевода":
//	0 00
//	1 01
//	2 02
//	3 10
//	4 11
//	5 12
//	6 20
//	7 21
//	8 22
//write[0-8]_ - написать вторую букву 
//movl[0-8] - ехать налево во выходному слову
//movl[0-8]_ - ехать налево по входному слову до стертой при копировании цифры и ставим ее на место
//preend - четверки moment (перейти к следующей букве входного слова, чтобы теперь ее обработать)
//end - копировать нечего, едем направо по выходному слову


0, ,<,mov  

mov, ,>,copy  mov,0,<,mov  mov,1,<,mov  
mov,2,<,mov  mov,3,<,mov  mov,4,<,mov  
mov,5,<,mov  mov,6,<,mov  mov,7,<,mov  
mov,8,<,mov  

copy, ,>,end  copy,0, ,copy0_  copy,1, ,copy1_  
copy,2, ,copy2_  copy,3, ,copy3_  copy,4, ,copy4_  
copy,5, ,copy5_  copy,6, ,copy6_  copy,7, ,copy7_  
copy,8, ,copy8_  

copy0_, ,>,movr0  

copy1_, ,>,movr1  

copy2_, ,>,movr2  

copy3_, ,>,movr3  

copy4_, ,>,movr4  

copy5_, ,>,movr5  

copy6_, ,>,movr6  

copy7_, ,>,movr7  

copy8_, ,>,movr8  

movr0, ,>,movr0_  movr0,0,>,movr0  movr0,1,>,movr0  
movr0,2,>,movr0  movr0,3,>,movr0  movr0,4,>,movr0  
movr0,5,>,movr0  movr0,6,>,movr0  movr0,7,>,movr0  
movr0,8,>,movr0  

movr1, ,>,movr1_  movr1,0,>,movr1  movr1,1,>,movr1  
movr1,2,>,movr1  movr1,3,>,movr1  movr1,4,>,movr1  
movr1,5,>,movr1  movr1,6,>,movr1  movr1,7,>,movr1  
movr1,8,>,movr1  

movr2, ,>,movr2_  movr2,0,>,movr2  movr2,1,>,movr2  
movr2,2,>,movr2  movr2,3,>,movr2  movr2,4,>,movr2  
movr2,5,>,movr2  movr2,6,>,movr2  movr2,7,>,movr2  
movr2,8,>,movr2  

movr3, ,>,movr3_  movr3,0,>,movr3  movr3,1,>,movr3  
movr3,2,>,movr3  movr3,3,>,movr3  movr3,4,>,movr3  
movr3,5,>,movr3  movr3,6,>,movr3  movr3,7,>,movr3  
movr3,8,>,movr3  

movr4, ,>,movr4_  movr4,0,>,movr4  movr4,1,>,movr4  
movr4,2,>,movr4  movr4,3,>,movr4  movr4,4,>,movr4  
movr4,5,>,movr4  movr4,6,>,movr4  movr4,7,>,movr4  
movr4,8,>,movr4  

movr5, ,>,movr5_  movr5,0,>,movr5  movr5,1,>,movr5  
movr5,2,>,movr5  movr5,3,>,movr5  movr5,4,>,movr5  
movr5,5,>,movr5  movr5,6,>,movr5  movr5,7,>,movr5  
movr5,8,>,movr5  

movr6, ,>,movr6_  movr6,0,>,movr6  movr6,1,>,movr6  
movr6,2,>,movr6  movr6,3,>,movr6  movr6,4,>,movr6  
movr6,5,>,movr6  movr6,6,>,movr6  movr6,7,>,movr6  
movr6,8,>,movr6  

movr7, ,>,movr7_  movr7,0,>,movr7  movr7,1,>,movr7  
movr7,2,>,movr7  movr7,3,>,movr7  movr7,4,>,movr7  
movr7,5,>,movr7  movr7,6,>,movr7  movr7,7,>,movr7  
movr7,8,>,movr7  

movr8, ,>,movr8_  movr8,0,>,movr8  movr8,1,>,movr8  
movr8,2,>,movr8  movr8,3,>,movr8  movr8,4,>,movr8  
movr8,5,>,movr8  movr8,6,>,movr8  movr8,7,>,movr8  
movr8,8,>,movr8  

movr0_, , ,write0  movr0_,0,>,movr0_  movr0_,1,>,movr0_  
movr0_,2,>,movr0_  

movr1_, , ,write1  movr1_,0,>,movr1_  movr1_,1,>,movr1_  
movr1_,2,>,movr1_  

movr2_, , ,write2  movr2_,0,>,movr2_  movr2_,1,>,movr2_  
movr2_,2,>,movr2_  

movr3_, , ,write3  movr3_,0,>,movr3_  movr3_,1,>,movr3_  
movr3_,2,>,movr3_  

movr4_, , ,write4  movr4_,0,>,movr4_  movr4_,1,>,movr4_  
movr4_,2,>,movr4_  

movr5_, , ,write5  movr5_,0,>,movr5_  movr5_,1,>,movr5_  
movr5_,2,>,movr5_  

movr6_, , ,write6  movr6_,0,>,movr6_  movr6_,1,>,movr6_  
movr6_,2,>,movr6_  

movr7_, , ,write7  movr7_,0,>,movr7_  movr7_,1,>,movr7_  
movr7_,2,>,movr7_  

movr8_, , ,write8  movr8_,0,>,movr8_  movr8_,1,>,movr8_  
movr8_,2,>,movr8_  

write0, ,0,write0  write0,0,>,write0_  

write1, ,0,write1  write1,0,>,write1_  

write2, ,0,write2  write2,0,>,write2_  

write3, ,1,write3  write3,1,>,write3_  

write4, ,1,write4  write4,1,>,write4_  

write5, ,1,write5  write5,1,>,write5_  

write6, ,2,write6  write6,2,>,write6_  

write7, ,2,write7  write7,2,>,write7_  

write8, ,2,write8  write8,2,>,write8_  

write0_, ,0,write0_  write0_,0,<,movl0  

write1_, ,1,write1_  write1_,1,<,movl1  

write2_, ,2,write2_  write2_,2,<,movl2  

write3_, ,0,write3_  write3_,0,<,movl3  

write4_, ,1,write4_  write4_,1,<,movl4  

write5_, ,2,write5_  write5_,2,<,movl5  

write6_, ,0,write6_  write6_,0,<,movl6  

write7_, ,1,write7_  write7_,1,<,movl7  

write8_, ,2,write8_  write8_,2,<,movl8  

movl0, ,<,movl0_  movl0,0,<,movl0  movl0,1,<,movl0  
movl0,2,<,movl0  

movl1, ,<,movl1_  movl1,0,<,movl1  movl1,1,<,movl1  
movl1,2,<,movl1  

movl2, ,<,movl2_  movl2,0,<,movl2  movl2,1,<,movl2  
movl2,2,<,movl2  

movl3, ,<,movl3_  movl3,0,<,movl3  movl3,1,<,movl3  
movl3,2,<,movl3  

movl4, ,<,movl4_  movl4,0,<,movl4  movl4,1,<,movl4  
movl4,2,<,movl4  

movl5, ,<,movl5_  movl5,0,<,movl5  movl5,1,<,movl5  
movl5,2,<,movl5  

movl6, ,<,movl6_  movl6,0,<,movl6  movl6,1,<,movl6  
movl6,2,<,movl6  

movl7, ,<,movl7_  movl7,0,<,movl7  movl7,1,<,movl7  
movl7,2,<,movl7  

movl8, ,<,movl8_  movl8,0,<,movl8  movl8,1,<,movl8  
movl8,2,<,movl8  

movl0_, ,0,preend  movl0_,0,<,movl0_  movl0_,1,<,movl0_  
movl0_,2,<,movl0_  movl0_,3,<,movl0_  movl0_,4,<,movl0_  
movl0_,5,<,movl0_  movl0_,6,<,movl0_  movl0_,7,<,movl0_  
movl0_,8,<,movl0_  

movl1_, ,1,preend  movl1_,0,<,movl1_  movl1_,1,<,movl1_  
movl1_,2,<,movl1_  movl1_,3,<,movl1_  movl1_,4,<,movl1_  
movl1_,5,<,movl1_  movl1_,6,<,movl1_  movl1_,7,<,movl1_  
movl1_,8,<,movl1_  

movl2_, ,2,preend  movl2_,0,<,movl2_  movl2_,1,<,movl2_  
movl2_,2,<,movl2_  movl2_,3,<,movl2_  movl2_,4,<,movl2_  
movl2_,5,<,movl2_  movl2_,6,<,movl2_  movl2_,7,<,movl2_  
movl2_,8,<,movl2_  

movl3_, ,3,preend  movl3_,0,<,movl3_  movl3_,1,<,movl3_  
movl3_,2,<,movl3_  movl3_,3,<,movl3_  movl3_,4,<,movl3_  
movl3_,5,<,movl3_  movl3_,6,<,movl3_  movl3_,7,<,movl3_  
movl3_,8,<,movl3_  

movl4_, ,4,preend  movl4_,0,<,movl4_  movl4_,1,<,movl4_  
movl4_,2,<,movl4_  movl4_,3,<,movl4_  movl4_,4,<,movl4_  
movl4_,5,<,movl4_  movl4_,6,<,movl4_  movl4_,7,<,movl4_  
movl4_,8,<,movl4_  

movl5_, ,5,preend  movl5_,0,<,movl5_  movl5_,1,<,movl5_  
movl5_,2,<,movl5_  movl5_,3,<,movl5_  movl5_,4,<,movl5_  
movl5_,5,<,movl5_  movl5_,6,<,movl5_  movl5_,7,<,movl5_  
movl5_,8,<,movl5_  

movl6_, ,6,preend  movl6_,0,<,movl6_  movl6_,1,<,movl6_  
movl6_,2,<,movl6_  movl6_,3,<,movl6_  movl6_,4,<,movl6_  
movl6_,5,<,movl6_  movl6_,6,<,movl6_  movl6_,7,<,movl6_  
movl6_,8,<,movl6_  

movl7_, ,7,preend  movl7_,0,<,movl7_  movl7_,1,<,movl7_  
movl7_,2,<,movl7_  movl7_,3,<,movl7_  movl7_,4,<,movl7_  
movl7_,5,<,movl7_  movl7_,6,<,movl7_  movl7_,7,<,movl7_  
movl7_,8,<,movl7_  

movl8_, ,8,preend  movl8_,0,<,movl8_  movl8_,1,<,movl8_  
movl8_,2,<,movl8_  movl8_,3,<,movl8_  movl8_,4,<,movl8_  
movl8_,5,<,movl8_  movl8_,6,<,movl8_  movl8_,7,<,movl8_  
movl8_,8,<,movl8_  

preend,0,>,copy  preend,1,>,copy  preend,2,>,copy  
preend,3,>,copy  preend,4,>,copy  preend,5,>,copy  
preend,6,>,copy  preend,7,>,copy  preend,8,>,copy  


end, ,#,end  end,0,>,end  end,1,>,end  
end,2,>,end  
