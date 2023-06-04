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
		prints("����");
		prints("1 - �������� �������");
		prints("2 - ������� �������");
		prints("3 - ������� ������");
		prints("4 - ����� ���-�� ������������ ����� ��� �������� ����������");
		prints("5 - ����������� �������� ������ ���������� � ������������ ����������� ������������ �����");
		prints("6 - �����");
		int c;
		int ii = 0;
		int max = -1;
		int count = 0;
		std::string name;
		cin >> c;
		switch (c)
		{
		case 1:
			prints("1 - � �����");
			prints("2 - �� �������");
			cin >> c;
			switch (c)
			{
			case 1:
				_Worker.add_worker(creator());
				break;
			case 2:
				prints("������� ������");
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
			prints("������� ������ ��� ��������");
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
	prints("1 - ���");
	prints("2 - �����");
	prints("3 - �����");
	prints("4 - �������");
	prints("5 - �����");
	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		return "���";
		break;

	case 2:
		return "�����";
		break;

	case 3:
		return "�����";
		break;
	case 4:
		return "�������";
		break;

	case 5:
		return "�����";
		break;
	}
}
int hours_f() {
	prints("������� ���������� �����");
	int c;
	cin >> c;
	return c;
}
int count_f() {
	prints("������� ���������� �����");
	int c;
	cin >> c;
	return c;
}

int type_f() {
	prints("��������:");
	prints("1 - ������");
	prints("2 - ��������");
	prints("3 - ������������ ������");
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