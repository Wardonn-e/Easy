#include <class/workers.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
using namespace workers;

void prints(std::string x);
EmployeePtr creator();
std::string name_f();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Employees _Worker;
	bool f_1 = 1;
	while (f_1) {
		prints("Меню");
		prints("1 - Вставить элемент");
		prints("2 - Удалить элемент");
		prints("3 - Вывести список");
		prints("4 - Найти кол-во оплачиваемых часов для заданной дисциплины");
		prints("5 - Определение названия первой дисциплины с максимальным количеством оплачиваемых часов");
		prints("6 - Выход");
		int c;
		int ii = 0;
		int max = -1;
		int count = 0;
		std::string name;
		cin >> c;
		switch (c)
		{
		case 1:
			prints("1 - В конец");
			prints("2 - По индексу");
			cin >> c;
			switch (c)
			{
			case 1:
				_Worker.add_worker(creator());
				break;
			case 2:
				prints("Введите индекс");
				int index;
				cin >> index;
				_Worker.insert_person(creator(), index);
				break;
			}

			break;
		case 2:
			for (int i = 0; i < _Worker.size(); i++) {
				_Worker[i] -> print();
			}
			prints("Введите индекс для удаления");
			cin >> c;
			_Worker.delete_person(c);
			for (int i = 0; i < _Worker.size(); i++) {
				_Worker[i] -> print();
			}
			break;
		case 3:
			for (int i = 0; i < _Worker.size(); i++) {
				_Worker[i] -> print();
			}
			break;
		case 4:
			name = name_f();

			for (int i = 0; i < _Worker.size(); i++) {
				if (_Worker[i]->get_name() == name) {
					count += _Worker[i]->get_hours();
				}
			}
			cout << name << " - " << count << endl;
			break;
			break;
		case 5:

			for (int i = 0; i < _Worker.size(); i++) {
				if (_Worker[i]->calculating_salary() > max) {
					max = _Worker[i]->calculating_salary();
					ii = i;
				}
			}
			_Worker[ii]->print();
			break;
		case 6:
			return 0;
			break;
		}
	}
}


void prints(std::string x) {
	cout << x << endl;
}
std::string name_f() {
	prints("1 - ООП");
	prints("2 - МатАн");
	prints("3 - АлГем");
	prints("4 - История");
	prints("5 - Физра");
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		return "ООП";
		break;

	case 2:
		return "МатАн";
		break;

	case 3:
		return "АлГем";
		break;
	case 4:
		return "История";
		break;

	case 5:
		return "Физра";
		break;
	}
}
int hours_f() {
	prints("Введите количество часов");
	int c;
	cin >> c;
	return c;
}
int count_f() {
	prints("Введите количество групп");
	int c;
	cin >> c;
	return c;
}

int type_f() {
	prints("Выберите:");
	prints("1 - Лекция");
	prints("2 - Практика");
	prints("3 - Лабараторная работа");
	int c;
	cin >> c;
	return c;
}

EmployeePtr creator() {
	int type = type_f();
	std::string name = name_f();
	int hours = hours_f();
	int count = count_f();
	switch (type)
	{
	case 1:
		return make_shared<Lecture>(name, hours, count);

	case 2:
		return make_shared<Practic>(name, hours, count);

	case 3:
		return make_shared<Labaratory>(name, hours, count);

	default:
		break;
	}
}