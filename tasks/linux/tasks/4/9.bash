# Выведите 5 строчек после слова eth0/enp0s3 при выводе команды ifconfig
ifconfig | grep -A 5 -e "eth0" -e "enp0s3" 
