# Разрешить запись в файл config.yml для владельца и группы, запретить для остальных 

chmod ug+w config.yml | chmod o-x config.yml
