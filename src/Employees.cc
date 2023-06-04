#include <class/workers.h>
#include <stdexcept>

using namespace workers;
using namespace std;

Employees::Employees(const Employees& other) {
	_worker.reserve(other.size());
	for (const auto& ptr: other._worker) {
		_worker.push_back(ptr->clone());
	}
}

int Employees::size() const {
	return static_cast<int>(_worker.size());
}

EmployeePtr Employees :: operator[](const int index) const {
	if (index < 0) {
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _worker.at(index);
}

Employees& Employees::operator=(const Employees& other) {
	Employees copy(other);
	copy.swap(*this);
	return *this;
}

void Employees::add_worker(const EmployeePtr f) {
	_worker.push_back(f);
}

void Employees::delete_person(int index) {
	_worker.erase(_worker.begin() + index);
}

void Employees::insert_person(EmployeePtr people, int index) {
	_worker.insert(_worker.begin() + index, people);
}

void Employees::swap(Employees& other) {
	std::swap(this->_worker, other._worker);
}

int workers::search_max_salary(const Employees& _worker) {
	int max_index = 0;
	float max_salary = 0;

	auto n = _worker.size();

	for (int i = 0; i < n; i++) {
		auto value = _worker[i]->calculating_salary();
		if (value > max_salary || max_index == -1) {
			max_index = i;
			max_salary = value;
		}
	}
	return max_index;
}
