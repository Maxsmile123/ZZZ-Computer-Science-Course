# Выведите номера строк, в которых встречается номер телефона с +7.
# Телефоны записаны так: +79447659120
grep -w  "+7"[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9[0-9]] | cat -n
