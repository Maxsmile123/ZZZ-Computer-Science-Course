# Выведи мне топ 5 файлов, в которых чаще всего встречается слово pizza

fing / -type f -exec grep -l "pizza" {} + | head -n 5
