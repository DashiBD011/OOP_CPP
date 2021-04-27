#include"Fraction.h"

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;          // Default constructor
	cout << A << endl;

	Fraction B = -5;      // Single-Argument constructor
	cout << B << endl;

	Fraction C(-1, 2);
	cout << C << endl;

	Fraction D(-2, 3, 4);
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

	Fraction A(2, 3, 4);
	Fraction B(5, 6, 7);
	/*A += B;
	cout << A.reduce() << endl;

	A -= B;
	cout << A.reduce() << endl;

	A *= B;
	cout << A.reduce() << endl;

	A /= B;
	cout << A.reduce() << endl;*/

	//cout << A << endl;
	//cout << A++ << endl;
	//cout << A << endl;
	//cout << ++A << endl;
	//cout << A << endl;
	//cout << A-- << endl;
	//cout << A << endl;
	//cout << --A << endl;
	operator>(A, B);

#ifdef ARITHMETICAL_OPERATORS_CHECK

	Fraction D(-52, 128);
	//cout << D << " = " << D.to_proper() << endl;
	//cout << D << " = " << D.to_improper() << endl;
	//cout << D << " = " << D.reduce() << endl;

	
	cout << A << "\t" << B << endl;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << B << " - " << A << " = " << B - A << endl;
	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << A / B << endl;
	cout << A << "\t" << B << endl;

#endif // OPERATORS_CHECK

	
}
