import argparse
import logging
import os
import shutil
import schema
import yaml

from random import shuffle
from schema import Schema, SchemaError

from typing import Dict
from typing import List
from typing import Optional


TASK_README_TEMPLATE = u'# Вариант № {var}\n**Сложность:** {comp}\n\n**Задание:** {description}\n---{other}'

DEFAULT_USERS_NUM = 28

CONFIG_SCHEMA = Schema({
    schema.Optional('users_list'): str,
    'template_dir': str,
    schema.Optional('task_descriptions'): {
        str : {
            schema.Optional('var_num'): int,
            schema.Optional('data_path'): str,
            schema.Optional('template_solution'): {
                str: str
            },
            schema.Optional('other_description'): str
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
        self.template_dir: Optional[str] = None
        self.copy_files: Dict[str, Dict[str, str]] = {}
        self.number_of_var: Dict[str, int] = {}
        self.var_data_paths: Dict[str, Optional[str]] = {}
        self.others_descriptions: Dict[str, str] = {}
        self.config_path = config_path
        self.students: List[str] = []
        self.load_config_()


    def load_config_(self) -> None:
        config = None
        with open(self.config_path, 'r') as file:
            config = yaml.safe_load(file)
        self.validate_config(config)

        self.template_dir = config['template_dir']
        self.students = self.load_users(config.get('users_list'))
        for task, description in config.get('task_descriptions', {}).items():
            self.number_of_var[task] = description.get('var_num', 1)
            self.var_data_paths[task] = description.get('data_path', None)
            self.copy_files[task] = description.get('template_solution', {})
            self.others_descriptions[task] = description.get('other_description', '')


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


    @staticmethod
    def load_users(filename: Optional[str]) -> List[str]:
        '''
        One student per row in file
        '''
        users: List[str] = []
        if filename and os.path.exists(filename):
            logging.info(f'[+] Loading users from {filename}')
            with open(filename, 'r', encoding='utf-8') as file:
                for user in file:
                    users.append(user.rstrip())
        else:
            logging.warning('[?] Unable load users from '
                            f'{filename if filename else "file"}\n'
                            'Generate default users.') 
            for i in range(1, DEFAULT_USERS_NUM):
                users.append(f'student{i}')

        return users

    @staticmethod
    def create_file(filepath: str) -> None:
        if filepath and not os.path.exists(filepath):
            open(filepath, 'a+').close()


    def generate_tasks_struct(self) -> None:
        if not os.path.exists(self.path):
            os.mkdir(self.path)

        path_to_lab: str = ''
        for lab, num_var in self.number_of_var.items():
            path_to_lab = os.path.join(self.path, lab)
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
                else:
                    logging.warning(f'[-] Already exists {path_to_var}')


    def generate_file_solution(
        self,
        path_to_tasks: str,
    ) -> None:
        lab = os.path.basename(os.path.dirname(path_to_tasks))
        for var in range(1, self.number_of_var[lab] + 1):
            for template_filename, solution_filename in self.copy_files[lab].items():
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


    @staticmethod
    # Return dict is: key = num_of_var, value = Tuple (сomplexity, task description)
    def var_parser_(path_to_var: Optional[str]) -> Optional[Dict[int, List[str]]]:
        if not path_to_var:
            return None
        path_to_var = os.path.join(path_to_var)
        if not os.path.exists(path_to_var):
            logging.warning(f'[-] File {path_to_var} isn\'t exists')
            return None

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
            path_to_var: str = '',
            other: str = ''
        ) -> None:

        lab = os.path.basename(os.path.dirname(path_to_tasks))
        lab_description = self.var_parser_(path_to_var)
        if lab_description is None:
            logging.warning(f'[-] Description for {lab} wasn\'t created.')
            return
        
        logging.info(f'[+] Generate for {lab}.')
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


    def generate_variants(self, path_to_tasks: str) -> None:
        if not path_to_tasks:
            return

        lab = os.path.basename(os.path.dirname(path_to_tasks))
        
        path_to_file = os.path.join(os.path.dirname(path_to_tasks), 'variants.md')
        with open(path_to_file, 'w', encoding='utf-8') as file:
            file.write(u'| **Студент** | **Вариант**|\n')
            file.write('|-------------|------------|\n')
            max_var = self.number_of_var[lab]
            variants = [(x % max_var) + 1 for x in range(1, max_var + 1 + len(self.students))]
            shuffle(variants)
            for i, user in enumerate(self.students):
                file.write(u'| {user} | [{var}](./tasks/{var}) |\n'.format(
                    user=user,
                    var=variants[i]
                ))


    def generate_repository(self, args) -> None:
        if args.clean:
            self.clear_repository()
        if args.struct:
            self.generate_tasks_struct()
        path_to_task: str = ''
        for task in self.number_of_var.keys():
            path_to_task = os.path.join(self.path, task, 'tasks')
            if args.vars:
                self.generate_variants(path_to_task)
            if args.files:
                self.generate_file_solution(path_to_task)
            if args.description:
                self.generate_task_description(
                    path_to_task,
                    self.var_data_paths[task],
                    self.others_descriptions[task]
                )

def main():
    parser = argparse.ArgumentParser(description='default all targets is off')
    parser.add_argument(
        '-c',
        '--clean',
        action='store_true',
        help='Clean current repository before generation')
    parser.add_argument(
        '--struct',
        action='store_true',
        help='Generate repository struct')
    parser.add_argument(
        '--files',
        action='store_true',
        help='Generate files with solutions and tests. Need full tempaltes directory')
    parser.add_argument(
        '--vars',
        action='store_true',
        help='Generate variants for students')
    parser.add_argument(
        '--description',
        action='store_true',
        help='Generate description for vars. Need full data directory. "-" is seperator')

    args = parser.parse_args()
    repo = Repository('tasks', './tools/config.yaml')
    repo.generate_repository(args)


if __name__ == '__main__':
    main()