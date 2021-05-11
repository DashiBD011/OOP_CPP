#pragma warning(disable:4326)
#include"Teacher.h"
#include"Graduate.h"


#define delimeter "\n--------------------------------------------------\n"
//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK

	/*Human human("Тупенко", "Василий", 18);
human.info();*/
	Student vasya("Тупенко", "Василий", 18, "программирование", "БД_011", 4);
	vasya.info();
	cout << delimeter << endl;
	Teacher Mariya("Иванова", "Мария", 56, "математика", 26);
	Mariya.info();
	cout << delimeter << endl;
	Graduate Tony("Montana", "Antonio", 25, "Современные технологии продаж", "BV_011", 80, "Распространение кокаина");
	Tony.info();
	cout << delimeter << endl;

#endif // INHERITANCE_CHECK

	//1. Generalization:
	Human* group[] =
	{
		new Student("Батодалаев", "Даши", 16, "РПО", "PD_011", 5),
		new Student("Загидуллин", "Линар", 32, "РПО", "PD_011", 5),
		new Graduate("Шугани", "Сергей", 15, "РПО", "PD_011", 5, "Защита персональных данных"),
		new Teacher("Einstein", "Albert", 141, "Atrophisics", 110),
		new Student("Маркин", "Даниил", 17, "РПО", "BV_011", 5),
		new Teacher("Richter", "Jeffrey", 45, "Windows development", 20),
		new Graduate("Курицын", "Алексей", 33, "РПО", "PD_011", 5, "Разработка распределенной нереляционной базы данных")
	};


	cout << sizeof(group) << endl;
	
	//2. Specialization:
	cout << delimeter << endl;

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->info();
		cout << typeid(*group[i]).name() << endl;
		if(typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]) ;
		if(typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]) ;
		if(typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]);
		cout << delimeter << endl;;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++) delete group[i];
	

}