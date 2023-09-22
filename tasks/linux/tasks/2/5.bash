#z Выведите топ 7 самых тяжёлых файлов в диапазоне от 1 до 100
find . -type f -size +1M -size -100M -exec ls -S {} \; | head -n 7
