# Распечатайте содержимое файла NotEmpty.txt, игнорируя пустые строки
cat NotEmpty.txt | grep -v "^$"
