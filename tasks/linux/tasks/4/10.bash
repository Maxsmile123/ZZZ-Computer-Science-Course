# Выведи мне топ 5 файлов, в которых чаще всего встречается слово pizza
grep -r -w -o 'pizza' . | sort -nr | uniq -c | head -5 | sort
