import os
import shutil
import yaml
import logging

from typing import Dict
from typing import List
from typing import Optional

from schema import Schema, SchemaError, Optional

TASK_README_TEMPLATE = u'# Вариант № {var}\n**Сложность:** {comp}\n\n**Задание:** {description}\n---{other}'

CONFIG_SCHEMA = Schema({
    Optional('users_list'): str,
    'template_dir': str,
    'path_to_task': str,
    Optional('task_descriptions'): {
        str : {
            Optional('var_num'): int,
            Optional('data_path'): str,
            Optional('template_solution'): {
                str: str
            },
            Optional('other_description'): str
        },
    },        
})

class TemplateFileNotFound(Exception):
    """Raise when template file isn't exist"""


class Repository:
    def __init__(
            self,
            path: str,
            config_path: str
        ) -> None:
        self.path = path
        self.template_dir: str = ''
        self.path_to_tasks: str = ''
        self.copy_files: Dict[str, Dict[str, str]] = {}
        self.number_of_var: Dict[str, int] = {}
        self.var_data_paths: Dict[str, Optional[str]] = {}
        self.others_descriptions: Dict[str, str] = {}
        self.config_path = config_path
        self.students: List[str] = []
        self.fill_()

    def fill_(self) -> None:
        config = None
        with open(self.config_path, 'r') as file:
            config = yaml.safe_load(file)
        self.validate_config(config)

        self.template_dir = config['template_dir']
        self.path_to_tasks = config['path_to_task']
        self.students = self.load_users(config.get('users_list'))
        for task, description in config.get('task_descriptions', {}).items():
            self.number_of_var[task] = description.get('var_num', 0)
            self.var_data_paths[task] = description.get('data_path', None)
            self.copy_files[task] = description.get('template_solution', {})
            self.others_descriptions[task] = description.get('other_description', '')

    def print_values(self) -> None:
        print('copy_files')
        for key, value in self.copy_files.items():
            print(f'{key} - {value}')

        print()

        print('number_of_var')
        for key, value in self.number_of_var.items():
            print(f'{key} - {value}')

        print()
        print('var_data_paths')
        for key, value in self.var_data_paths.items():
            print(f'{key} - {value}')

        print()
        print('others_descriptions')
        for key, value in self.others_descriptions.items():
            print(f'{key} - {value}')


    @staticmethod
    def validate_config(config) -> None:
        try:
            CONFIG_SCHEMA.validate(config)
        except SchemaError as e:
            logging.error("[-] Config isn't valid!")
            raise e


    def clear_repository(self) -> None:
        path_to_lab = '' 
        for lab in self.number_of_var.keys():
            path_to_lab = os.path.join(self.path, lab)
            try:
                shutil.rmtree(path_to_lab)
            except FileNotFoundError:
                logging.warning(f"[?] {path_to_lab} isn't exist for delete")


    def load_users(self, filename: str) -> List[str]:
        users: List[str] = []
        if filename:
            with open(filename, 'r') as file:
                users.append(file.readline())
        
        return users


    def create_file(filepath: str) -> None:
        open(filepath, 'a+').close()

    
    def generate(self) -> None:
        self.generate_repository()


    def generate_tasks_struct(self) -> None:
        if not os.path.exists(self.path_to_tasks):
            os.mkdir(self.path_to_tasks)

        path_to_lab = ''
        for lab, num_var in self.number_of_var.items():
            path_to_lab = os.path.join(self.path_to_tasks, lab)
            if not os.path.exists(path_to_lab):
                logging.info(f'[+] Create dir {path_to_lab}')
                os.mkdir(path_to_lab)

            self.create_file(os.path.join(path_to_lab, 'readme.md'))
            path_to_lab_tasks = os.path.join(path_to_lab, 'tasks')
            if not os.path.exists(path_to_lab_tasks):
                logging.info(f'[+] Create dir {path_to_lab_tasks}')
                os.mkdir(path_to_lab_tasks)

            for i in range(1, num_var + 1):
                path_to_var = os.path.join(path_to_lab_tasks, str(i))
                if not os.path.exists(path_to_var):
                    logging.info(f'[+] Create dir {path_to_var}')
                    os.mkdir(path_to_var)
                self.create_file(os.path.join(path_to_var, 'readme.md'))


    def generate_file_solution(
        self,
        path_to_tasks: str,
    ) -> None:
        lab = os.path.dirname(path_to_tasks)
        for var in range(1, self.number_of_var[lab] + 1):
            for template_filename, solution_filename in self.copy_files.values():
                    t_path = os.path.join(self.template_dir, template_filename)
                    s_path = os.path.join(
                        path_to_tasks,
                        str(var),
                        solution_filename
                    )
                    if not os.path.exists(t_path):
                        raise TemplateFileNotFound(f"{t_path} isn't exist")
                    
                    if os.path.exists(s_path):
                        logging.info(f'[+] Delete {s_path}')
                        os.remove(s_path)
                    logging.info(f'Try copy from {t_path} to {s_path}')
                    try:
                        shutil.copyfile(t_path, s_path)
                    except Exception as e:
                        logging.warning(f"[?] Copy {t_path} raise exception: {e}")


    def var_parser_(self, path_to_var: str) -> Dict[int, List[str]]:
        # Dict is: key = num_of_var, value = Tuple (сomplexity, task description)
        lab_description: Dict[int, List[str, str]] = {}
        with open(path_to_var, 'r', encoding='utf-8') as file:
            for string in file.readlines():
                lst_string = string.split('-')
                if len(lst_string) != 2:
                    raise Exception(f'Wrong string format: {lst_string}')
                if '***' in lst_string[0]:
                    lab_description[int(lst_string[0].replace('*** ', ''))] = [
                        'Очень сложно', lst_string[1]
                    ]
                elif '**' in lst_string[0]:
                    lab_description[int(lst_string[0].replace('** ', ''))] = [
                        'Сложно', lst_string[1]
                    ]
                elif '*' in lst_string[0]:
                    lab_description[int(lst_string[0].replace('* ', ''))] = [
                        'Чуть сложнее cтандартного', lst_string[1]
                    ]
                else:
                    lab_description[int(lst_string[0].replace(' ', ''))] = [
                        'Стандартный', lst_string[1]
                    ]

        return lab_description


    def generate_task_description(
            self,
            path_to_tasks: str,
            path_to_var: str,
            other: str = ''
        ) -> None:
        lab = os.path.dirname(path_to_tasks)
        lab_description = self.var_parser_(os.path(path_to_var))
        for var in range(1, self.number_of_var[lab] + 1):
            path_to_task_readme = os.path.join(path_to_tasks, str(var), 'readme.md')
            if not os.path.exists(path_to_task_readme):
                self.create_file(path_to_task_readme)

            with open(path_to_task_readme, 'w', encoding='utf-8') as file:
                file.write(TASK_README_TEMPLATE.format(
                    var=var,
                    description=lab_description[var][1],
                    comp=lab_description[var][0],
                    other=other
                ))


    def generate_repository(self) -> None:
        self.clear_repository()
        self.generate_tasks_struct()
        path_to_task: str = ''
        for task in self.number_of_var.keys():
            path_to_task = os.path.join(self.path, task, 'tasks')
            self.generate_file_solution(path_to_task)
            self.generate_task_description(
                path_to_task,
                self.var_data_paths[task],
                self.others_descriptions[task]
            )


if __name__ == '__main__':
    repo = Repository('tasks', './tools/config.yaml')
    repo.print_values()
    # repo.generate()