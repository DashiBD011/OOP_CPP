#include<iostream>
#include<string>
#include<ctime>
using namespace std;

#define HUMAN_TAKE_PARAMETERS const string& last_name, const string& first_name, const unsigned int& age
#define STUDENT_TAKE_PARAMETERS const string& speciality, const string& group, double rating
#define TEACHER_TAKE_PARAMETERS const string& speciality, unsigned int experience

#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
#define STUDENT_GIVE_PARAMETERS rating, group, speciality
#define TEACHER_GIVE_PARAMETERS speciality, experience

class Human
{
	string last_name;
	string first_name;
	//time_t birth_date;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	/*const time_t& get_birth_date()const
	{
		return birth_date;
	}*/
	const unsigned int& get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	/*void set_birth_date(const time_t& birth_date)
	{
		this->birth_date = birth_date;
	}*/
	void set_age(const unsigned int& age)
	{
		this->age = age;
	}
	//      Constructors
	Human(const string& last_name, const string& first_name, const unsigned int& age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		//set_birth_date(birth_date);
		set_age(age);
		cout << "HConstructor:\t"<< this << endl;

	}
	~Human()
	{
		cout << "HDestructor:\t" << this <<endl;
	}

	//      Methods
	void info()const
	{
		//cout <<"Last name:  "<< last_name << endl;
		//cout <<"First name: "<< first_name << endl;
		////cout <<"Birth date: "<< age << endl;
		//cout << "Age:\t" << age << " years" << endl;
		cout << last_name << " " << first_name << ", " << age << " лет" << endl;
	}
};
class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	//     Constructor
	Student(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS
	       ):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void info()const
	{
		Human::info();
		cout << speciality << ", " << group << ", успеваемость: " << rating << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	Teacher
	(
		HUMAN_TAKE_PARAMETERS,
		TEACHER_TAKE_PARAMETERS
	):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_experience(experience);
		set_speciality(speciality);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void info()
	{
		Human::info();
		cout << speciality << ", опыт преподавания: "<< experience <<" лет" << endl;
	}
};

class Graduate :public Student
{
	string topic;    // Тема проекта
public:
	const string& get_topic()const
	{
		return topic;
	}
	void set_topic(string& topic)
	{
		this->topic = topic;

	}

	Graduate
	(
		HUMAN_TAKE_PARAMETERS,
		STUDENT_TAKE_PARAMETERS,
		const string& topic
    ):Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS),
		topic(topic)
	{
		cout << "GConstructor:\t\t" << this << endl;

	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void info()const
	{
		Student::info();
		cout <<"Тема "<< topic << endl;
	}
};

#define delimeter "\n--------------------------------------------------\n"
#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK

	/*Human human("Тупенко", "Василий", 18);
human.info();*/
	Student vasya("Тупенко", "Василий", 18, "программирование", "БД_011", 4.5);
	vasya.info();
	cout << delimeter << endl;
	Teacher Mariya("Иванова", "Мария", 56, "математика", 26);
	Mariya.info();
	cout << delimeter << endl;
	Graduate Tony("Montana", "Antonio", 25, "Современные технологии продаж", "BV_011", 80, "Распространение кокаина");
	Tony.info();
	cout << delimeter << endl;

#endif // INHERITANCE_CHECK


}