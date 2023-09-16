# Сожмите архив trash.tar с максимальной степенью сжатия
tar -cf - trash | gzip -9 > trash.tar.gz
