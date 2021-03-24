#include<iostream>
using namespace std;

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
		cout << "Constructors" << this << endl;
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
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;

	}

	//          Methods
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	double distance(const Point& other)const
	{
		/*double x_distance = this->x - other.x;
		double y_distance = other.y - this->y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/

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
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/

	return sqrt(pow(A.get_x() - B.get_x(),2) + pow(A.get_y() - B.get_y(),2));
}

//#define INTRO
//#define CONSTRUCTORS
#define DISTANCE

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

	Point A(2, 3);
	Point B(4, 5);
	A.print();
	B.print();
	cout << A.distance(B) << endl;
	cout << distance(A, B) << endl;
}