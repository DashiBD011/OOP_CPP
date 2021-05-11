#include"Student.h"

const string& Student::get_speciality()const
{
	return speciality;
}
const string& Student::get_group()const
{
	return group;
}
double Student::get_rating()const
{
	return rating;
}
void Student::set_speciality(const string& speciality)
{
	this->speciality = speciality;
}
void Student::set_group(const string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
//     Constructor
Student::Student(
	HUMAN_TAKE_PARAMETERS,
	STUDENT_GET_PARAMETERS
) :Human(HUMAN_GIVE_PARAMETERS)
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SDestructor:\t" << this << endl;
}
void Student::info()const
{
	Human::info();
	cout << speciality << ", " << group << ", успеваемость: " << rating << endl;
}

ostream& operator<<(ostream& os, const Student& obj)
{
	
	return os << (Human)obj << ", " << obj.get_speciality() << ", " << obj.get_group() << ", " << obj.get_rating()<<" ";
}
