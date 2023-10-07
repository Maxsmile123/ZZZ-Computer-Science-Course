# Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger.

find / -type f -name "*backdoor*.py" -o -name "*trojan*.py" -o -name "*keylogger*.py"
