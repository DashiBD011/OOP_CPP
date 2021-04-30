#include"Teacher.h"

const string& Teacher::get_speciality()const
{
	return speciality;
}
unsigned int Teacher::get_experience()const
{
	return experience;
}
void Teacher::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(unsigned int experience)
{
	this->experience = experience;
}

Teacher::Teacher
(
	HUMAN_TAKE_PARAMETERS,
	TEACHER_GET_PARAMETERS
) :Human(HUMAN_GIVE_PARAMETERS)
{
	set_experience(experience);
	set_speciality(speciality);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}

void Teacher::info()const
{
	Human::info();
	cout << speciality << ", ���� ������������: " << experience << " ���" << endl;
}

