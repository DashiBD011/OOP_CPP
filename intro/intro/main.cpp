#include<iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

//Создание структуры
class Point
{
	//Структура Point описывает точки на плоскости
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors
	//Point()
	//{
	//	// Конструктор без параметров создает точку в начале координат
	//	x = y = int();
	//	cout << "Default Constructor:\t  " << this << endl;
	//}
	//Point(double x)
	//{
	//	// Конструктор с одним параметром создает точку на прямой
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstructor:" << this << endl;
	//}
	//Point(double x, double y)
	//{
	//	// Конструктор с параметрами создает точку на плоскости
	//	this->x = x;
	//	this->y = y;
	//	cout << "Constructor:\t\t" << this <<endl;
	//}
	Point(double x = 0, double y = 0)
	{
		// Этот конструктор может быть вызван: 
		//-без параметров
		//-с одним параметром
		//-с двумя параметрами
		this->x = x;
		this->y = y;
		cout << "Constructors\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		// other - это другой объект, копию которого мы создаем
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//          Operators
    Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "operator+=\t\t" << this << endl;
		return *this;
	}

	//             Increment/Decrement

	Point& operator++()
	{
		this->x++;
		this->y++;
		cout << "Prefix increment:\t" << this << endl;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; //CopyConstructor
		this->x++;
		this->y++;
		cout << "Postfix increment:\t" << this << endl;
		return old;

	}

	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "operator+" << endl;
		return result;
	}*/
	/*Point operator-(const Point& other)const
	{
		
		Point result(this->x - other.x, this->y - other.y);;
		cout << "operator-" << endl;
		return result;
	}*/
	/*Point operator*(const Point& other)const
	{
		
		return Point(this->x * other.x, this->y * other.y);
	}*/
	/*Point operator/(const Point& other)
	{
		return Point(this->x / other.x, this->y / other.y);
	
	}*/

	//          Methods
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	double distance(const Point& other)const
	{
		return sqrt(pow(this->x - other.x,2)+pow(other.y - this->y,2));	
	}
};

// Создавая структуру или класс, мы создаем новый тип данных,
// а объявляя объекты этого класса или структуры, мы создаем переменные нашего типа
// Классы и структур еще называют пользовательскими типами данных


//                    КЛАСС - ЭТО ТИП ДАННЫХ
//                СТРУКТУРА - ЭТО ТИП ДАННЫХ
//                   ОБЪЕКТ - ЭТО САМАЯ ОБЫЧНАЯ ПЕРЕМЕННАЯ

double distance(const Point& A, const Point& B)
{
	return sqrt(pow(A.get_x() - B.get_x(),2) + pow(A.get_y() - B.get_y(),2));
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}
Point operator-(const Point& left, const Point& right)
{
	Point result
	{
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	};
	cout << "Global minus" << endl;
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}
Point operator/(const Point& left, const Point& right)
{
	return Point(left.get_x() / right.get_x(), left.get_y() / right.get_y());
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\t" << "Y = " << obj.get_y();

}

//#define INTRO
//#define CONSTRUCTORS
//#define ASSIGNMENT_CHECK
//#define OPERATOR_EXAMPLES
//#define DISTANCE
//#define OPERATORS_OVERLOADDS
//#define ARITHMETICAL_OPERATORS
//#define COMPOUND_ASSIGNMENTS

void main()
{
	setlocale(LC_ALL, "");

#ifdef INTRO
	int a;     // Объявление переменной "а", типа 'int'
	Point A;   // Объявление объекта 'A' типа 'Point' 

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A;
	cout << pA->get_x() << "\t" << pA->get_y() << endl;

#endif // INTRO

#ifdef CONSTRUCTORS

	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;


	Point B = 5;   // Single-Argument constructor
	B.print();

	Point C(8);
	C.print();

	Point D{ 12 };
	D.print();

	Point E(5, 3); // Parametrized Constructor
	E.print();     
	              
	Point F = E;   // CopyConstructor
	Point G;       // DefaultConstructor
	G = D;         // CopyAssignment - operator=
	G.print();
#endif // CONSTRUCTORS

#ifdef ASSIGNMENT_CHECK
	//int a, b, c;
	//a = b = c = 0;

	Point A(0, 5);
	Point B(4, 7);
	Point C;
	 
	//C = A + B;
	//cout << C << endl; Оказывается, оператор '<<' тоже нужно перегрузить, но я не понял как
	A + B;
	A - B;
	A* B;
	A / B;


#endif // ASSIGNMENT_CHECK

#ifdef OPERATOR_EXAMPLES
	cout << A + B << endl;           // Неявный вызов оператора '+'	
	cout << A.operator+(B) << endl;  // Явный вызов оператора '+', перегруженного в классе
	cout << operator+(A, B) << endl; // Явный вызов оператора '+', перегруженного за классом

#endif // OPERATOR_EXAMPLES

#ifdef DISTANCE
	Point A(2, 3);
	Point B(4, 5);

	A.print();
	B.print();
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
#endif // DISTANCE

#ifdef OPERATORS_OVERLOADDS


#ifdef ARITHMETICAL_OPERATORS
	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();

	Point D = A - B;
	D.print();

	Point E = A * B;
	E.print();

	//Point F = A.operator/(B);
	Point F = operator/(A, B);
	F.print();

	(A * B).print();
#endif // ARITHMETICAL_OPERATORS

#ifdef COMPOUND_ASSIGNMENTS
	Point A(2, 3);
	Point B(4, 5);
	A += B;
	A.print();
	/*++A;
	A.print();
	A++;
	A.print();*/
	cout << A++ << endl;
	cout << A << endl;
	cout << ++A << endl;
	cout << A << endl;
	
#endif // COMPOUND_ASSIGNMENTS


#endif // OPERATORS_OVERLOADDS
	
}