#include <iostream>


using namespace std;

class Employee {
	private:
		const int id; // Making Employee Id const
		char* name;
		double salary;
		static int count; // variable to keep track of number of current no Employee exist in the program
	public:
		//setter and getter fucntion
		// removing setEmpId member function becasue we can't change const Id
		//once the object is initialize
		void setEmpName(const char* empName);
		void setEmpSalary(double empSalary);
		int getEmpId() const; // const memeber Function to get Employee id
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
		
		static int totalNumberOfEmployee();
};

int Employee::count = 0; // initializing static count variable

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
	++count; // incrementing count by 1 when new object is created using defatult constructor
}

// Initializing Id data member to using initializer list
Employee::Employee(int empId, const char* empName, double empSalary) : id(empId), name(nullptr), salary(0)
{
	// setEmpId(empId) removed
	setEmpName(empName);
	setEmpSalary(empSalary);
	
	++count; // incrementing count by 1 when new object is created using pararmeterized constructor
}
// using initializer list so we can initilize id before Employee creation
Employee::Employee(const Employee& rhs) : id(rhs.id)
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
	
//	id = rhs.id; removing this due to const id
	salary = rhs.salary;
}

Employee::~Employee()
{
	if(name != nullptr)
	{
		delete []name;
		name = nullptr;
	}
	
	--count; // decrementing count by 1 when object is destroyed
}

void Employee::display()
{
	cout << "Employee Id: " << id
	<< "\nEmployee Name; " << name
	<< "\nEmployee Salary: " << salary;
}

int main()
{
	
	Employee e1(10, "A", 5000), e2(20, "B", 3000), e3(30, "C", 7000);
	
	int i = 0;
	
	cout << "Employee Id: " << e1.getEmpId()
	<< "\nEmployee Id: " << e2.getEmpId()
	<< "\nEmployee Id: " << e3.getEmpId();
}