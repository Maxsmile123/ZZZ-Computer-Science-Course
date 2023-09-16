# Изменить расширение всех txt файлов в формат md
find . -type f -name "*.txt" -exec sh -c 'mv "$0" "${0%.txt}.md"' {} \;
