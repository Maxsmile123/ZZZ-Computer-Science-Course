# Написать скрипт антивируса, который сканирует все файлы в текущей и поддиректорях на предмет файлов, содержащих следующие строки:
# Trojan
# Process
# Backdoor
grep -rwE "Trojan|Process|Backdoor"
