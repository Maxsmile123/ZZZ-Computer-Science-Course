# Найдите все py файлы, содержащие в названии любое из трёх слов: backdoor, trojan, keylogger.
find. -maxdepth -name "*py" -name "*keylogger*" | -name "trojan" | -name "backdoor" 

