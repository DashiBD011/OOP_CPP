#include<iostream>
#include<fstream>
using namespace std;

enum employee
{
	hourly,
	permanent
};

class Employee
{
	string last_name;
	string first_name;
	employee salary_type;
	unsigned int age;
	int salary;
	
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	employee& get_salary_type()
	{
		return salary_type;
	}
	int get_salary()
	{
		return salary;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	void set_salary_type(employee salary_type)
	{
		this->salary_type = salary_type;
	}
	void set_salary(int salary)
	{
		this->salary = salary;
	}
	//      Constructors
	Employee(const string& last_name, const string& first_name, unsigned int age, int salary, employee salary_type)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		set_salary(salary);
		set_salary_type(salary_type);
		//cout << "Constructor:\t" << this << endl;

	}
	~Employee()
	{
		//cout << "Destructor:\t" << this << endl;
	}

	//      Methods
	void info()const
	{
		cout << last_name << " " << first_name << ", " << age << " лет ,"<< salary <<" руб, ";
		cout << (salary_type == 0 ? " c почасовой з/п" : " с постоянной з/п") << endl;
	}
};

int Calc(Employee& someone)
{
	int time;
	if (someone.get_salary_type() == 0)
	{
		cout << "Время работы(ч): "; cin >> time;
		cout <<"З/п "<< "сотрудника " << someone.get_last_name() << someone.get_first_name() << " составляет: ";
		return someone.get_salary() * time;
	}
	else
	{
		cout << "Время работы(мес): "; cin >> time;
		cout << "З/п " << "сотрудника " << someone.get_last_name() << someone.get_first_name()  << " составляет: ";
		return someone.get_salary() * time;
	}
}

#define delimeter "\n----------------------------------------------------\n"

Employee ReadFromFile()
{
	ifstream fin;
	fin.open("members_of_the_group.csv");
	
}

void main()
{
	setlocale(LC_ALL, "");
	Employee chelovek("Ян ", "Липецкий", 44, 50000, permanent);
	Employee chelovek2("Иван ", "Быстрюк", 19, 500, hourly);
	Employee chelovek3("Олег ", "Калчук", 24, 40500, permanent);

	ifstream fin;
	fin.open("members_of_the_group.csv");


	chelovek.info();
	cout << Calc(chelovek) << endl;

	cout << delimeter << endl;
	
	chelovek2.info();
	cout << Calc(chelovek2) << endl;
	
	cout << delimeter << endl;
	
	chelovek3.info();
	cout << Calc(chelovek3) << endl;

}