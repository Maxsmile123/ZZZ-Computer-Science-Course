# Написать bash скрипт, удаляющий пустые файлы в текущей директории
find . -maxdepth 1 -type f -empty -delete
