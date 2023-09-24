# Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger.
find / -type f -name "*.py" -a name "*backdoor.py" -a name "*trojan.py" -a name "*keylogger.py"
