#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String;
	String operator+(const String& left, const  String& right);
class String
{
	char* str;    // указатель на строку динамической памяти
	int size;     // размер строки
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	//            Constructors
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char [size] {};
		cout << (size==80?"Default":"Size")<<"Constructor:\t" << this << endl;
		
	}
	String(const char* str): String(strlen(str)+1) //  делегирования конструкторы с 1 параметром
		                                           // типа int, чтобы он выделил память
	{
		//this->size = strlen(str)+1;
		//this->str = new char[size] {};
		strcpy(this->str, str);
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other):String(other.str)
	{
		/*this->size = other.size;
		this->str = new char[size] {};*/
		//strcpy(this->str, other.str);
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//this->size = other.size;
		//this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[]this->str;
		cout << "Destructor:\t\t" << this <<endl;
	}
	//            Methods
	void print()const
	{
		cout << "str:\t" << str << endl;
		cout << "size:\t" << size << endl;
	}

	//            Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;  // 0)Проверить не является ли другой объект этим объектом
		delete[]this->str;                // 1)Впервую очередь удаляем старое значение объекта
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		delete[]this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;

	}
	const char& operator[](int i)const
	{
		return this -> str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}
	/*String& operator+=(const String& other)
	{
		String buffer = this->str;
		delete[]this->str;
		this->str = new char[(this->size + other.size) - 1]{};
		strcpy(this->str, buffer.str);
		strcat(this->str, other.str);
		return *this;
	}*/
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left,const  String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)
	{
		result[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result[i + left.get_size() - 1] = right[i];
	}*/
	strcpy(result.get_str(), left.get_str());
	strcat(result.get_str(), right.get_str());
	return result;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENTS_CHECK
//#define OPERATOR_PLUS_CHECK
#define delimeter "\n-------------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

	String str;
	str.print();

	String str2(5);          // Преобразование 
	str2.print();

	String str3 = "Hello!";
	str3.print();

	cout << str3 << endl;

	String str4 = str3;
	cout << "Str4 - " << str4 << endl;

	String str5;
	str5 = str4;
	cout << "Str5 - " << str5 << endl;

#endif // CONSTRUCTORS_CHECK


#ifdef ASSIGNMENTS_CHECK

	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;


#endif // ASSIGNMENTS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimeter << endl;
	String str3;
	str3 = str1 + str2;    // оператор '+' будет выполнять конкатенацию(слияние) строк 
	cout << delimeter << endl;
	cout << str3 << endl;

	/*str1 += str2;
	cout << str1 << endl;*/
#endif // OPERATOR_PLUS_CHECK


	////////////////////////////////////////////////начиная отсюда новая ветка
	String str1;            // Default
	str1.print();
	String str2 = "Hello";  // Single argument
	str2.print();
	String str3("World");   // Single argument
	str3.print();
	String str4();          // Объявдение функции str4,
	                        // которая ничего не принимает и возвращает значения типа string
	String str5{};    // Явно вызывается Default constructor
	str5.print();
	String str6{7};   // Size constructor 
	str6.print();
	String str7{ "Привет" };
	str7.print();

	String str8 = str7;
	str8.print();
	cout << delimeter << endl;
	cout << str2 + str3 << endl;
	/////////////constructor_delegetion_DONE

	/////////////////////new branch(string_separated)

} 