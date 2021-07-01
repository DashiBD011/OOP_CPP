#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-------------------------------------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR
//#define EXCEPTIONS_IN_VECTOR

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "size:     " << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;  // ���������������
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

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef STL_ARRAY
	// array - ��� ���������, ������� ������ ������ � ���� ������������ �������.
	const int n = 5;
	std::array<int, n> arr = { 3,5,8,13,21 };

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // STL_ARRAY

#ifdef STL_VECTOR
	// vector - ��� ���������, ������� ������ ������ � ���� ������������� �������.

	int index;
	int value;

	std::vector <int> vec = { 0,1,1,2,3,5,8,13,21 ,34};
	vector_properties(vec);
	vec.push_back(55);
    //std::vector<int>::iterator it;
	//it = vec.begin();

	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� ��������: "; cin >> value;
	vec.insert(vec.begin()+index, value);        // insert()
	vector_print(vec);

	cout << delimeter << endl;

	cout << "������� ������ ���������� ��������:   "; cin >> index;
	vec.erase(vec.begin() + index);              // erase()
	vector_print(vec);

	cout << delimeter << endl;

	vector_reverse_print(vec);


#ifdef EXCEPTIONS_IN_VECTOR
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			// [] - index operator(subscript operator)
			//cout << vec[i] << tab;   // O�������[] �� ������� ���������� ��� ������ �� ������� �������
			cout << vec.at(i) << tab;  // M���� at() ������� ����������(out of range exception) ��� ������ �� ������� �������
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

#endif // EXCEPTIONS_IN_VECTOR
	
#endif // STL_VECTOR




}