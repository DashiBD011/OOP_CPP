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
		this->x - other.x;
		this->y - other.y;
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
	Point& operator+(const Point& other)
	{
		int x_summ = this->x+other.x;
		int y_summ = this->y+other.y;
		cout << "A(" << x << "," << y << ") + B(" << other.x << "," << other.y << ") = " << "C(" << x_summ << "," << y_summ << ")" << endl;
		return *this;
	}
	Point& operator-(const Point& other)
	{
		int x_dif = this->x - other.x;
		int y_dif = this->y - other.y;
		cout << "A(" << x << "," << y << ") - B(" << other.x << "," << other.y << ") = " << "C(" << x_dif << "," << y_dif << ")" << endl;
		return *this;
	}
	Point& operator*(const Point& other)
	{
		int x_product = this->x * other.x;
		int y_product = this->y * other.y;
		cout << "A(" << x << "," << y << ") * B(" << other.x << "," << other.y << ") = " << "C(" << x_product << "," << y_product << ")" << endl;
		return *this;
	}
	Point& operator/(const Point& other)
	{
		double x_division = this->x / other.x;
		double y_division = this->y / other.y;
		cout << "A(" << x << "," << y << ") / B(" << other.x << "," << other.y << ") = " << "C(" << x_division << "," << y_division << ")" << endl;
		return *this;
	}

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

std::ostream& operator<<(std::ostream &os, const Point& C)
{
	return os << C << endl;
}

//#define INTRO
//#define CONSTRUCTORS
#define ASSIGNMENT_CHECK
//#define OPERATOR_EXAMPLES
//#define DISTANCE

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

}