# Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger.
find -type f \( -name "trojan.py" -or -name "keylogger.py" -or -name "backdoor.py" \)
