#include<iostream>
#include<array>
#include<vector>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-------------------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define EXCEPTIONS_IN_VECTOR
#define STL_LIST

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;  // вместительность
	cout << "Maxsize:  " << vec.max_size() << endl;
}
template<typename T>void vector_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
template<typename T>void vector_reverse_print(const std::vector<T>& vec)
{
	for (typename std::vector<T>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

template<typename T>void list_print(const std::list<T>& list)
{
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STL_ARRAY
	// array - это контейнер, который хранит данные в виде статического массива.
	const int n = 5;
	std::array<int, n> arr = { 3,5,8,13,21 };

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // STL_ARRAY

#ifdef STL_VECTOR
	// vector - это контейнер, который хранит данные в виде динамического массива.

	int index;
	int value;

	std::vector <int> vec = { 0,1,1,2,3,5,8,13,21 ,34 };
	vector_properties(vec);
	vec.push_back(55);
	//it = vec.begin();

	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение: "; cin >> value;

	std::vector<int>::iterator position = vec.begin() + index;

	vec.insert(position, value);        // insert()
	vector_print(vec);

	cout << delimeter << endl;

	cout << "Введите индекс удаляемого элемента:   "; cin >> index;
	position = vec.begin() + index;
	vec.erase(position);              // erase()
	vector_print(vec);
	vector_reverse_print(vec);
	
	cout << delimeter << endl;
	vector_properties(vec);
	vec.assign({ 1024, 2048, 3072 });
	vector_properties(vec);
	vector_print(vec);


#ifdef EXCEPTIONS_IN_VECTOR
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			// [] - index operator(subscript operator)
			//cout << vec[i] << tab;   // Oператор[] не бросает исключение при выходе за пределы вектора
			cout << vec.at(i) << tab;  // Mетод at() бросает исключение(out of range exception) при выходе за пределы вектора
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

#endif // EXCEPTIONS_IN_VECTOR
	
#endif // STL_VECTOR

#ifdef STL_LIST

	std::list<int> list = {3, 5, 8, 13, 21};
	std::vector<int> vec = {3, 5, 8, 13, 21};
	/*for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << tab;   // оператор [] не допустим в списках, поскольку очень сильно понижает производительность
	}*/
	list_print(list);
	/*cout << "VecSize: " << vec.size() << endl;
	cout << "VecMaxSize: " << vec.max_size() << endl;

	cout << "ListSize: " << list.size() << endl;
	cout << "ListMaxSize: " << list.max_size() << endl;*/

	int index;
	int value;

	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)	position++;
	
	list.insert(position++, value);
	list_print(list);

#endif // STL_LIST



}