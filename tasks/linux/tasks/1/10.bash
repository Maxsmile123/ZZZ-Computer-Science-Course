# Написать скрипт антивируса, который сканирует все файлы в текущей и поддиректорях на предмет файлов, содержащих следующие строки:
# Trojan
# Process
# Backdoor
grep -r -l -x -e "Trojan" -e "Process" -e "Backdoor" # Для целых строк
grep -r -l -e "Trojan" -e "Process" -e "Backdoor" # Для подстрок
