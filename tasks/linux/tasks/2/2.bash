# Создать файлы формата txt, в которых название - одна каждая буква латинского алфавита:
# Example: a.txt, b.txt... z.txt

for i in q w e r t y u i o p a s d f g h j k l z x c v b n m; do 
    touch "$i.txt"
done
