# Изменить расширение всех txt файлов в формат md

for f in *.txt; do mv -- "$f" "${f%.txt}.md"; done
