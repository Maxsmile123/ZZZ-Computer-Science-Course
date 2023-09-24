# Найди мне все файлы формата *mp4, которые не являются ремиксами. 
# Файл считается ремиксом, если в названии встречается слово "remix".

find . -type f -name "*.mp4" -not -name "*remix*" -print