# Парсер для гугл таблички https://docs.google.com/spreadsheets/d/1q5eB01pE91ZGe7DxdSxfcIDt5XvG43PzmHvkKmNFcEQ/edit?usp=sharing


import csv


def main():
    data = []
    with open('from9to3.tsv', 'r') as f:
        reader = csv.reader(f, delimiter='\t', quotechar='"')
        for row in reader:
            data.append(row)
    data[0][1] = ' '
    c = 0
    for i in range(1, 69):  # состояний всего 68 + 1 строка обозначений
        for j in range(1, 11):  # алфавит из 10 букв + 1 столбец обозначений
            if data[i][j] != '':
                print(f'{data[i][0]},{data[0][j]},{data[i][j]}', end='  ')
                c += 1
                if c % 3 == 0:
                    print('')
        print('\n')
        c = 0


if __name__ == "__main__":
    main()
