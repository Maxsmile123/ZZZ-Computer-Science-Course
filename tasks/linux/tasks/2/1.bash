# Изменить расширение всех txt файлов в формат md
find . -name "*.txt" -exec mv {} {}.md  \;
это единственное решиние, которое я придумал, без скачивания rename
