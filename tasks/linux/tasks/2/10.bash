# Написать bash скрипт, удаляющий пустые файлы в текущей директории
find . -type f -maxdepth 1 -empty -exec rm {} \;
