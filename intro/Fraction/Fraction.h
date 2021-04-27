#pragma once
//Fraction - дробь
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
ostream& operator<<(ostream& os, const Fraction& obj);
void operator>(Fraction left, Fraction right);

class Fraction
{
	bool minus;
	int integer;     // Целая часть
	int numerator;   // Числитель
	int denominator; // Знаменатель
public:
	bool get_minus()const;
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_minus(bool minus);
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//////////////////////////////////////////////////////
	Fraction& set_minus_to_number();
	Fraction& get_minus_from_number();

	// Consturctors
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	~Fraction();

	Fraction& to_proper();
	Fraction& to_improper();
	Fraction& reduce();
	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

};

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK