// Решите поставленную задачу в формате четвёрок

00, ,<,00
00,1,=,i.0ds
00,0,=,i.0ds


// 1 digit search (i)


i.0ds,1,<,i.1ds
i.0ds,0,<,i.1ds

i.1ds,1,<,i.2ds
i.1ds,0,<,i.2ds


// remembering number 1 (i)


i.2ds,0,>,i.0rn
i.2ds,1,>,i.1rn


i.0rn,0,>,i.0.0rn
i.0rn,1,>,i.0.1rn

i.1rn,0,>,i.1.0rn
i.1rn,1,>,i.1.1rn


i.0.0rn,0,>,i.0.0.0rn
i.0.0rn,1,>,i.0.0.1rn

i.0.1rn,0,>,i.0.1.0rn
i.0.1rn,1,>,i.0.1.1rn

i.1.0rn,0,>,i.1.0.0rn
i.1.0rn,1,>,i.1.0.1rn

i.1.1rn,0,>,i.1.1.0rn
i.1.1rn,1,>,i.1.1.1rn


// 1 digit place


i.0.0.0rn, ,>,i0.0dp

i.0.0.1rn, ,>,i1.0dp

i.0.1.0rn, ,>,i2.0dp

i.0.1.1rn, ,>,i3.0dp

i.1.0.0rn, ,>,i4.0dp

i.1.0.1rn, ,>,i5.0dp

i.1.1.0rn, ,>,i6.0dp

i.1.1.1rn, ,>,i7.0dp


i0.0dp, ,>,i0.1dp
i0.1dp, ,>,i0.put
i0.put, ,0,2i.0ds

i1.0dp, ,>,i1.1dp
i1.1dp, ,>,i1.put
i1.put, ,1,2i.0ds

i2.0dp, ,>,i2.1dp
i2.1dp, ,>,i2.put
i2.put, ,2,2i.0ds

i3.0dp, ,>,i3.1dp
i3.1dp, ,>,i3.put
i3.put, ,3,2i.0ds

i4.0dp, ,>,i4.1dp
i4.1dp, ,>,i4.put
i4.put, ,4,2i.0ds

i5.0dp, ,>,i5.1dp
i5.1dp, ,>,i5.put
i5.put, ,5,2i.0ds

i6.0dp, ,>,i6.1dp
i6.1dp, ,>,i6.put
i6.put, ,6,2i.0ds

i7.0dp, ,>,i7.1dp
i7.1dp, ,>,i7.put
i7.put, ,7,2i.0ds


// 2 digit search (2i)

2i.0ds, ,<,2i.1ds
2i.0ds,0,<,2i.1ds
2i.0ds,1,<,2i.1ds
2i.0ds,2,<,2i.1ds
2i.0ds,3,<,2i.1ds
2i.0ds,4,<,2i.1ds
2i.0ds,5,<,2i.1ds
2i.0ds,6,<,2i.1ds
2i.0ds,7,<,2i.1ds

2i.1ds, ,<,2i.1ds
2i.1ds,0,<,2i.2ds
2i.1ds,1,<,2i.2ds

2i.2ds,0,<,2i.3ds
2i.2ds,1,<,2i.3ds

2i.3ds,0,<,2i.4ds
2i.3ds,1,<,2i.4ds

2i.4ds,0,<,2i.5ds
2i.4ds,1,<,2i.5ds

2i.5ds,0,<,2i.6ds
2i.5ds,1,<,2i.6ds


// remembering number 2 (2i)

2i.6ds,0,>,2i.0rn
2i.6ds,1,>,2i.1rn

2i.0rn,0,>,2i.0.0rn
2i.0rn,1,>,2i.0.1rn

2i.1rn,0,>,2i.1.0rn
2i.1rn,1,>,2i.1.1rn


2i.0.0rn,0,>,2i.0.0.0rn
2i.0.0rn,1,>,2i.0.0.1rn

2i.0.1rn,0,>,2i.0.1.0rn
2i.0.1rn,1,>,2i.0.1.1rn

2i.1.0rn,0,>,2i.1.0.0rn
2i.1.0rn,1,>,2i.1.0.1rn

2i.1.1rn,0,>,2i.1.1.0rn
2i.1.1rn,1,>,2i.1.1.1rn


// 2 digit place


2i.0.0.0rn,0,>,2i.0.0.0rn
2i.0.0.0rn,1,>,2i.0.0.0rn
2i.0.0.0rn, ,>,2i0.0dp

2i.0.0.1rn,0,>,2i.0.0.1rn
2i.0.0.1rn,1,>,2i.0.0.1rn
2i.0.0.1rn, ,>,2i1.0dp

2i.0.1.0rn,0,>,2i.0.1.0rn
2i.0.1.0rn,1,>,2i.0.1.0rn
2i.0.1.0rn, ,>,2i2.0dp

2i.0.1.1rn,0,>,2i.0.1.1rn
2i.0.1.1rn,1,>,2i.0.1.1rn
2i.0.1.1rn, ,>,2i3.0dp

2i.1.0.0rn,0,>,2i.1.0.0rn
2i.1.0.0rn,1,>,2i.1.0.0rn
2i.1.0.0rn, ,>,2i4.0dp

2i.1.0.1rn,0,>,2i.1.0.1rn
2i.1.0.1rn,1,>,2i.1.0.1rn
2i.1.0.1rn, ,>,2i5.0dp

2i.1.1.0rn,0,>,2i.1.1.0rn
2i.1.1.0rn,1,>,2i.1.1.0rn
2i.1.1.0rn, ,>,2i6.0dp

2i.1.1.1rn,0,>,2i.1.1.1rn
2i.1.1.1rn,1,>,2i.1.1.1rn
2i.1.1.1rn, ,>,2i7.0dp


2i0.0dp, ,>,2i0.put
2i0.put, ,0,3i.0ds

2i1.0dp, ,>,2i1.put
2i1.put, ,1,3i.0ds

2i2.0dp, ,>,2i2.put
2i2.put, ,2,3i.0ds

2i3.0dp, ,>,2i3.put
2i3.put, ,3,3i.0ds

2i4.0dp, ,>,2i4.put
2i4.put, ,4,3i.0ds

2i5.0dp, ,>,2i5.put
2i5.put, ,5,3i.0ds

2i6.0dp, ,>,2i6.put
2i6.put, ,6,3i.0ds

2i7.0dp, ,>,2i7.put
2i7.put, ,7,3i.0ds


// 3 digit search (3i)

3i.0ds, ,<,3i.1ds
3i.0ds,0,<,3i.1ds
3i.0ds,1,<,3i.1ds
3i.0ds,2,<,3i.1ds
3i.0ds,3,<,3i.1ds
3i.0ds,4,<,3i.1ds
3i.0ds,5,<,3i.1ds
3i.0ds,6,<,3i.1ds
3i.0ds,7,<,3i.1ds

3i.1ds, ,<,3i.2ds
3i.2ds, ,<,3i.3ds

3i.3ds,0,<,3i.4ds
3i.3ds,1,<,3i.4ds

3i.4ds,0,<,3i.5ds
3i.4ds,1,<,3i.5ds

3i.5ds,0,<,3i.6ds
3i.5ds,1,<,3i.6ds

3i.6ds,0,<,3i.7ds
3i.6ds,1,<,3i.7ds

3i.7ds,0,<,3i.8ds
3i.7ds,1,<,3i.8ds

3i.8ds,0,<,3i.9ds
3i.8ds,1,<,3i.9ds

3i.9ds,0,<,3i.10ds
3i.9ds,1,<,3i.10ds


// remembering number 3 (3i)


3i.10ds,0,>,3i.0rn
3i.10ds,1,>,3i.1rn

3i.0rn,0,>,3i.0.0rn
3i.0rn,1,>,3i.0.1rn

3i.1rn,0,>,3i.1.0rn
3i.1rn,1,>,3i.1.1rn


// 3 digit place

3i.0.0rn,0,>,3i.0.0rn
3i.0.0rn,1,>,3i.0.0rn
3i.0.0rn, ,>,3i0.0dp

3i.0.1rn,0,>,3i.0.1rn
3i.0.1rn,1,>,3i.0.1rn
3i.0.1rn, ,>,3i0.1dp

3i.1.0rn,0,>,3i.1.0rn
3i.1.0rn,1,>,3i.1.0rn
3i.1.0rn, ,>,3i1.0dp

3i.1.1rn,0,>,3i.1.1rn
3i.1.1rn,1,>,3i.1.1rn
3i.1.1rn, ,>,3i1.1dp


3i0.0dp, ,0,end
3i0.1dp, ,1,end
3i1.0dp, ,2,end
3i1.1dp, ,3,end


// end


end, ,=,finish
end,0,>,end
end,1,>,end
end,2,>,end
end,3,>,end
end,4,>,end
end,5,>,end
end,6,>,end
end,7,>,end


finish, ,#,finish