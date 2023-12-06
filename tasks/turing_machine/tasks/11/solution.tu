# формат строки: " {num}="

00, ,<,goleft

#копирование

goleft,=,<,goleft
goleft,0,<,goleft
goleft,1,<,goleft
goleft, , ,copy

copy,0,*,gorightif0 copy,1,*,gorightif1 copy, ,>,copy copy,=,>,goright

gorightif0,*,>,gorightif0 gorightif0,=,>,gorightif0 gorightif0,0,>,gorightif0 gorightif0,1,>,gorightif0 gorightif0, , ,paste0

gorightif1,*,>,gorightif1 gorightif1,=,>,gorightif1 gorightif1,0,>,gorightif1 gorightif1,1,>,gorightif1 gorightif1, , ,paste1

paste0, ,0,left0
paste1, ,1,left1

left0, ,<,left0 left0,1,<,left0 left0,0,<,left0 left0,=,<,left0 left0,*,0,gonextnum
left1, ,<,left1 left1,1,<,left1 left1,0,<,left1 left1,=,<,left1 left1,*,1,gonextnum

gonextnum,0,>,copy gonextnum,1,>,copy

goright,1,>,goright goright,0,>,goright goright, ,<,num

#замена

num,0,<,if0 num,1,<,if1 num,=,#,num

if0,0,0,next if0,1,0,goback1 if0, ,#,num
if1,1,1,next if1,0,1,goback0 if1, ,#,num

goback0,1,>,replaceon0
replaceon0,1,0,return

goback1,0,>,replaceon1
replaceon1,0,1,return

return,0,<,next return,1,<,next

next,1,<,num next,0,<,num
