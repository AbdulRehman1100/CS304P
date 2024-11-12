#include <iostream>
using namespace std;

class Employee {
	private:
		int id;
		char* name;
		double salary;
	public:
		//setter and getter fucntion
		void setEmpId(int empId);
		void setEmpName(const char* empName);
		void setEmpSalary(double empSalary);
		int getEmpId() const;
		const char* getEmpName() const;
		double getEmpSalary() const;
		//default constructor
		Employee();
		// paramterized constructor
		Employee(int empId, const char* empName, double empSalary);
		//deep Copy Constructor
		Employee(const Employee& rhs);
		//destructor
		~Employee();
		void display();
};

void Employee::setEmpId(int empId)
{
	if(empId > 0)
	{
		id = empId;
	}
	else
	{
		id = 1;
	}
}

void Employee::setEmpName(const char* empName)
{
	if(name != nullptr)
	{
		delete []name;
		name = nullptr;
	}
	
	if(empName != nullptr)
	{
		name = new char [strlen(empName) + 1];
		strcpy(name,empName);
	}
}

void Employee::setEmpSalary(double empSalary)
{
	if(empSalary > 0)
	{
		salary = empSalary;
	}
	else
	{
		salary = 0;
	}
}

int Employee::getEmpId() const
{
	return id;
}

const char* Employee::getEmpName() const
{
	return name;
}

double Employee::getEmpSalary() const
{
	return salary;
}

Employee::Employee() : id(1), name(nullptr), salary(0)
{
	
}

Employee::Employee(int empId, const char* empName, double empSalary) : id(1), name(nullptr), salary(0)
{
	setEmpName(empName);
	setEmpId(empId);
	setEmpSalary(empSalary);
}

Employee::Employee(const Employee& rhs)
{
	if(rhs.name != nullptr)
	{
		name = new char [strlen(rhs.name) + 1];
		strcpy(name, rhs.name);
	}
	else
	{
		name = nullptr;
	}
	
	id = rhs.id;
	salary = rhs.salary;
}

Employee::~Employee()
{
	if(name != nullptr)
	{
		delete []name;
		name = nullptr;
	}
}

void Employee::display()
{
	cout << "Employee Id: " << id
	<< "\nEmployee Name; " << name
	<< "\nEmployee Salary: " << salary;
}

int main()
{
	
	Employee emp1(10, "xyz", 5000);
	Employee emp2(emp1);
	
	cout << "The data members of object 1:" << endl;
	emp1.display();
	cout << "\n\nThe data members of object 2:" << endl;
	emp2.display();
	return 0;
	
}