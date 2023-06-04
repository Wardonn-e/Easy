#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>

namespace workers {

	class Employee;
	using EmployeePtr = std::shared_ptr<Employee>;

	class Employee {
	public:

		Employee(std::string name, int hours);

		virtual double calculating_salary() const = 0;

		virtual EmployeePtr clone() const = 0;

		std::string get_name() const;
		void set_name(std::string worker_name);

		int get_hours() const;
		void set_hours(int hours);

		virtual ~Employee() = default;

		virtual std::ostream& print(std::ostream & = std::cout) const = 0;

	protected:

		std::string _name;
		int _hours;

		Employee() = default;
		Employee(const Employee&) = default;
		Employee& operator=(const Employee&) = default;
	};

	class Lecture : public Employee {
	private:
		int _groups;

	public:

		Lecture(std::string name, int hours, int groups);

		int get_groups() const;
		void set_groups(int groups);

		double calculating_salary() const override;

		EmployeePtr clone() const override;

		std::ostream& print(std::ostream& os) const override;

	};

	class Labaratory : public Employee {
	private:

		int _groups;

	public:

		Labaratory(std::string name, int hours, int groups);

		int get_groups() const;
		void set_groups(int groups);

		double calculating_salary() const override;

		EmployeePtr clone() const override;

		std::ostream& print(std::ostream& os) const override;

	};
	class Practic : public Employee {
	private:

		int _groups;

	public:

		Practic(std::string name, int hours, int groups);

		int get_groups() const;
		void set_groups(int groups);

		double calculating_salary() const override;

		EmployeePtr clone() const override;

		std::ostream& print(std::ostream& os) const override;

	};

	class Employees {
	private:

		std::vector<EmployeePtr> _worker;

	public:

		Employees() = default;
		Employees(const Employees& other);
		int size() const;
		EmployeePtr operator[](int index) const;
		Employees& operator=(const Employees& other);
		void add_worker(EmployeePtr f);
		void delete_person(int index);
		void insert_person(EmployeePtr people, int index);
		void swap(Employees& other);
	};

	int search_max_salary(const Employees& _worker);
}