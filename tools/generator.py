import codecs
import os
import shutil
import time
from typing import Dict
from typing import List


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
        shutil.copyfile(os.path.join(path, 'template' + POINT[lab]),
                        os.path.join(path, str(i), 'solution' + POINT[lab]))
        if lab == 'finite_state_machine':
            shutil.copyfile(os.path.join(path, 'template.txt'),
                        os.path.join(path, str(i), 'solution.txt'))


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




def generate_repository(users: List[str]) -> None:
    base_path = 'tasks'
    for lab in NUMBER_OF_VAR.keys():
        if lab in BLACK_LIST:
            continue
        rebuild_struct(os.path.join(base_path, lab))



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