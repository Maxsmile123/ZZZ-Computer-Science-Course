import codecs
import os
import shutil
import time
from typing import Dict
from typing import List
from typing import Tuple


TASK_README_TEMPLATE = u'# Вариант № {var}\n**Сложность:** {comp}\n\n**Задание:** {description}\n---{other}'


NUMBER_OF_VAR: Dict[str, int] = {
    'linux': 1,
    'hack': 1,
    'turing_machine': 53,
    'turing_diagrams': 48,
    'nam': 42,
    'reverse': 27,
    'geometry': 30,
    'finite_state_machine': 43,
    'integers': 33,
    'bitsets': 29,
    'linerization': 28,
    'matrix': 35,
    'taylor': 28,
    'numerical_methods': 28
}

BLACK_LIST = ['linux', 'hack', 'reverse']

POINT: Dict[str, int] = {
    'nam': '.nam',
    'geometry': '.c',
    'finite_state_machine': '.c',
    'integers': '.c',
    'bitsets': '.c',
    'linerization': '.c',
    'matrix': '.c',
    'taylor': '.c',
    'numerical_methods': '.c'
}

TASK_TO_LAB: Dict[str, str]

ADDITIONAL_TASKS = {
    'KP6': u'Реализуйте взаимодействие с таблицей через язык запросов SQL. Необходимо ' \
    'реализовать, чтобы через SQL можно было удалить строки из таблицы, вставить новые, найти нужные, ' \
    'обновлять старые записи. Интерфейс: пользователь через stdin вводит SQL запрос и получает вывод. ' \
    'Если SQL запрос неккоректный, то необходимо вызвать исключение.',
    'KP7': u'Написать бенчмарк сравнения с std::vector.',
    'KP8': u'Написать бенчмарк сравнения с std::list/std::forward_list',
    'KP9': u'Написать бенчмарк сравнения с std::sort',
    'lab21': u'Написать решение задачи ещё и на Python.',
    'lab22': '-',
    'lab23': u'Почитать про AVL-дерево, красно-чёрные дерево, B-дерево, B+ дерево, дерево отрезков.',
    'lab24': '-',
    'lab25': u'Почитать про систему сборки Cmake',
    'lab26': u'Написать бенчмарк сравнения с std::deque/std::stack/std::queue',
}

def generate_var_dir() -> None:
    for lab, num_var in NUMBER_OF_VAR.items():
        path = 'tasks'
        path = os.path.join(path, lab)
        try:
            os.mkdir(path)
        except FileExistsError:
                pass
        open(os.path.join(path, 'readme.md'), 'a+').close()
        for i in range(1, num_var + 1):
            try:
                os.mkdir(os.path.join(path, str(i)))
                open(os.path.join(os.path.join(path, str(i)), 'readme.md'), 'a+').close()
            except FileExistsError:
                pass

def clear() -> None:
    path = 'tasks'
    for lab in NUMBER_OF_VAR.keys():
        try:
            shutil.rmtree(os.path.join(path, lab))
        except FileNotFoundError:
            pass

def generate_file_solution(path: str) -> None:
    lab = os.path.basename(path)
    for i in range(1, NUMBER_OF_VAR[lab] + 1):
        if lab == 'finite_state_machine':
            shutil.copyfile(os.path.join(path, 'regex.c'),
                        os.path.join(path, 'tasks', str(i), 'regex.c'))
            os.remove(os.path.join(os.path.join(path, 'tasks', str(i), 'solution.txt')))
            os.rename(os.path.join(os.path.join(path, 'tasks', str(i), 'solution.c')),
                    os.path.join(os.path.join(path, 'tasks', str(i), 'FSM.c')))
            
        # shutil.copyfile(os.path.join(path, 'template' + POINT[lab]),
        #                 os.path.join(path, str(i), 'solution' + POINT[lab]))


def rebuild_struct(path: str) -> None:
    lab = os.path.basename(path)
    path_to_tasks = os.path.join(path, 'tasks')
    if not os.path.exists(path_to_tasks):
        os.mkdir(path_to_tasks)
    for i in range(1, NUMBER_OF_VAR[lab] + 1):
        task_path = os.path.join(path, str(i))
        if os.path.exists(task_path) and not os.path.exists(os.path.join(path_to_tasks, str(i))):
            shutil.copytree(task_path, os.path.join(path_to_tasks, str(i)))
        if os.path.exists(task_path):
            shutil.rmtree(task_path)

def var_parser(path_to_var: str) -> Dict[int, Tuple[str, str]]:
    # Dict is: key = num_of_var, value = Tuple (сomplexity, task description)
    lab_description: Dict[int, List[str, str]] = {}
    with open(path_to_var, 'r', encoding='utf-8') as file:
        for string in file.readlines():
            lst_string = string.split('-')
            if len(lst_string) != 2:
                raise Exception(f'Wrong string format: {lst_string}')
            if '***' in lst_string[0]:
                lab_description[int(lst_string[0].replace('*** ', ''))] = ['Очень сложно', lst_string[1]]
            elif '**' in lst_string[0]:
                lab_description[int(lst_string[0].replace('** ', ''))] = ['Сложно', lst_string[1]]
            elif '*' in lst_string[0]:
                lab_description[int(lst_string[0].replace('* ', ''))] = ['Чуть сложнее cтандартного', lst_string[1]]
            else:
                lab_description[int(lst_string[0].replace(' ', ''))] = ['Стандартный', lst_string[1]]

    return lab_description


def generate_task_description(path_to_lab: str, path_to_var: str, other: str = '') -> None:
    lab = os.path.basename(path_to_lab)
    lab_description = var_parser(path_to_var)
    for var in range(1, NUMBER_OF_VAR[lab] + 1):
        path_to_task_readme = os.path.join(path_to_lab, 'tasks', str(var), 'readme.md')
        if not os.path.exists(path_to_task_readme):
            open(path_to_task_readme, 'a+').close()
        with open(path_to_task_readme, 'w', encoding='utf-8') as file:
            file.write(TASK_README_TEMPLATE.format(
                var=var,
                description=lab_description[var][1],
                comp=lab_description[var][0],
                other=other
            ))



def generate_repository(users: List[str]) -> None:
    base_path = 'tasks' 
    generate_task_description(os.path.join(base_path, 'integers'), os.path.join('tools', 'I12-2011.txt'))
    for lab in NUMBER_OF_VAR.keys():
        if lab in BLACK_LIST:
            continue
        generate_file_solution(os.path.join(base_path, lab))



def load_users(filename: str) -> List[str]:
    users: List[str] = []
    with open(filename) as file:
        users.append(file.readline())
    
    return users

def main():
    # filename = '../students.txt'
    # users = load_users(filename)
    users = []
    generate_repository(users)


main()