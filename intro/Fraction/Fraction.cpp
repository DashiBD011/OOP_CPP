#include"Fraction.h"
bool Fraction::get_minus()const
{
	return minus;
}
int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_minus(bool minus)
{
	this->minus = minus;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
//////////////////////////////////////////////////////
Fraction& Fraction::set_minus_to_number()
{
	if (minus)
	{
		integer = -integer;
		numerator = -numerator;
		minus = false;
	}
	return *this;
}
Fraction& Fraction::get_minus_from_number()
{
	if (integer < 0)
	{
		integer = -integer;
		minus = true;
	}
	if (numerator < 0)
	{
		numerator = -numerator;
		minus = true;
	}
	return *this;
}

// Consturctors
Fraction::Fraction()
{
	this->minus = false;
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
	cout << "Constructor0:\t" << this << endl;

}
Fraction::Fraction(int integer)
{
	this->minus = false;
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
	if (integer < 0)
	{
		minus = true;
		this->integer = -integer;
	}
#ifdef DEBUG
	cout << "Constructor1:\t" << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int numerator, int denominator)
{
	this->minus = false;
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
	if (numerator < 0)
	{
		minus = true;
		this->numerator = -numerator;
	}
#ifdef DEBUG
	cout << "Constructor2:\t" << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->minus = false;
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
	if (integer < 0)
	{
		minus = true;
		this->integer = -integer;
	}
	if (numerator < 0)
	{
		minus = true;
		this->numerator = -numerator;
	}
#ifdef DEBUG
	cout << "Constructor3:\t" << this << endl;
#endif // DEBUG


}
Fraction::~Fraction()
{
#ifdef DEBUG
	cout << "Destructor:\t" << this << endl;
#endif // DEBUG



}

Fraction& Fraction::to_proper()
{
	/*if(integer>=0)integer += numerator / denominator;
	else integer -= numerator / denominator;*/
	get_minus_from_number();
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()
{
	get_minus_from_number();
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::reduce()
{

	for (int j = 0; j < abs(numerator); j++)
	{
		for (int i = 1; i <= abs(numerator); i++)
		{
			if (denominator % i == 0 && numerator % i == 0)
			{
				numerator /= i;
				denominator /= i;
			}
		}
	}

	return *this;
}
Fraction& Fraction::operator=(const Fraction& other)
{
	this->minus = other.minus;
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
#ifdef DEBUG
	cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG
	return *this;
}
Fraction& Fraction::operator+=(const Fraction& other)
{
	return *this = *this + other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
	return *this = *this - other;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator++()
{
	minus ? this->integer-- : this->integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	minus ? this->integer-- : this->integer++;
	return old;
}
Fraction& Fraction::operator--()
{
	minus ? this->integer++ : this->integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	minus ? this->integer++ : this->integer--;
	return old;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_minus())os << "(-";
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	if (obj.get_minus())os << ")";
	return os;
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	left.set_minus_to_number();
	right.set_minus_to_number();

	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper().get_minus_from_number();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_proper().set_minus_to_number();
	right.to_proper().set_minus_to_number();
	return Fraction
	(
		left.get_integer() - right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().get_minus_from_number();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().get_minus_from_number();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	Fraction result
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	);
	result.to_proper();
	if (left.get_minus() || right.get_minus())result.set_minus(true);
	if (left.get_minus() && right.get_minus())result.set_minus(false);
	return result;

}
void operator>(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	double first = left.get_numerator() / left.get_denominator();
	double second = right.get_numerator() / right.get_denominator();
	if (first > second)cout << left.to_proper() << " > " << right.to_proper() << endl;
	if (first < second)cout << left.to_proper() << " < " << right.to_proper() << endl;
	if (first == second)cout << left.to_proper() << " == " << right.to_proper() << endl;
	if (first != second)cout << left.to_proper() << " != " << right.to_proper() << endl;
	if (first >= second)cout << left.to_proper() << " >= " << right.to_proper() << endl;
	if (first <= second)cout << left.to_proper() << " <= " << right.to_proper() << endl;
}

