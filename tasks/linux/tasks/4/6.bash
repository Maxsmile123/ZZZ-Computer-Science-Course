# Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger

find -name "*backdoor*.py" -o -name "*trojan*.py" -o -name "*keylogger*.py"
