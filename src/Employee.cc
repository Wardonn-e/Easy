#include <class/workers.h>

#include <cassert>
#include <stdexcept>
#include <ctime>
#include <iostream>

using namespace std;
using namespace workers;

Employee::Employee(std::string name, int hours) :
	_name(name),
	_hours(hours)
{}

std::string Employee::get_name() const {
	return _name;
}

void Employee::set_name(std::string worker_name) {
	_name = worker_name;
}


int Employee::get_hours() const {
	return _hours;
}

void Employee::set_hours(int hours) {
	_hours = hours;
}



Labaratory::Labaratory(std::string name, int hours, int groups) :
	Employee(name, hours),
	_groups(groups) {}

void Labaratory::set_groups(int groups) {
	_groups = groups;
}
int Labaratory::get_groups() const {
	return _groups;
}

EmployeePtr Labaratory::clone() const {
	return make_shared<Labaratory>(_name, _hours, _groups);
}

std::ostream& Labaratory::print(std::ostream& out) const {
	out << "Лабараторная работа" << "\n"
		<< "Имя: " << get_name() << "\n"
		<< "Часы: " << get_hours() << "\n"
		<< "Количество подгрупп: " << get_groups() << "\n"
		<< "Количество оплачиваемых часов: " << calculating_salary() << "\n"
		<< endl << endl;
	return out;
}


Practic::Practic(std::string name, int hours, int groups) :
	Employee(name, hours),
	_groups(groups) {}

void Practic::set_groups(int groups) {
	_groups = groups;
}
int Practic::get_groups() const {
	return _groups;
}

EmployeePtr Practic::clone() const {
	return make_shared<Practic>(_name, _hours, _groups);
}

std::ostream& Practic::print(std::ostream& out) const {
	out << "Лабараторная работа" << "\n"
		<< "Имя: " << get_name() << "\n"
		<< "Часы: " << get_hours() << "\n"
		<< "Количество групп: " << get_groups() << "\n"
		<< "Количество оплачиваемых часов: " << calculating_salary() << "\n"
		<< endl << endl;
	return out;
}



Lecture::Lecture(std::string name, int hours, int groups) :
	Employee(name, hours),
	_groups(groups) {}

void Lecture::set_groups(int groups) {
	_groups = groups;
}
int Lecture::get_groups() const {
	return _groups;
}

EmployeePtr Lecture::clone() const {
	return make_shared<Lecture>(_name, _hours, _groups);
}

std::ostream& Lecture::print(std::ostream& out) const {
	out << "Лабараторная работа" << "\n"
		<< "Имя: " << get_name() << "\n"
		<< "Часы: " << get_hours() << "\n"
		<< "Количество групп: " << get_groups() << "\n"
		<< "Количество оплачиваемых часов: " << calculating_salary() << "\n"
		<< endl << endl;
	return out;
}


double Lecture::calculating_salary() const{
	return _hours;
}
double Labaratory::calculating_salary() const {
	return _hours * _groups;
}
double Practic::calculating_salary() const {
	return _hours * _groups;
}