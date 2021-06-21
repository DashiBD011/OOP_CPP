#include"List.h"
//#include"List.cpp"
//#include"Element.h"
//#include"Element.cpp"
//#include"Iterator.h"
//#include"Iterator.cpp"
//#include"ReverseIterator.h"
//#include"ReverseIterator.cpp"


//#define BASE_CHECK
//#define SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR
//#define ITERATORS_CHECK
//#define COPY_METHODS_CHECK
#define TEMPLATES_CHECK

template<typename T>
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (T i : right)cat.push_back(i);
	return cat;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	//int n; cout << "Введите размер списка:"; cin >> n;

#ifdef BASE_CHECK
	int n = 5;
	int value;
	int index;
	List<int> list;
	for (int i = 0; i < n; i++)
		list.push_back(rand() % 100);
	//list.push_front(rand() % 100);

	list.print();
	cout << delimeter << endl;;

	//cout << "Введите значение добавляемого элемента: "; cin >> value;
	//list.push_back(value);
	//list.print();
	//list.print_reverse();


	/*list.pop_back();
	list.print();*/

	//cout << delimeter << endl;;
	//cout << "Введите индекс добавляемого элемента: "; cin >> index;
	//cout << "Введите значение добавляемого элемента: "; cin >> value;
	//list.insert(index,value);
	//list.print();
	//cout << delimeter << endl;;
	//list.print_reverse();
	//
	//cout << delimeter << endl;;
	//cout << "Введите индекс удаляемого значения: "; cin >> index;
	//list.erase(index);
	//list.print();
	//list.print_reverse();

#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR
			//List list = n;      // Type conversion from int to List
	List list(n);
	for (size_t i = 0; i < list.getSize(); i++) list[i] = rand() % 100;
	for (size_t i = 0; i < list.getSize(); i++)cout << list[i] << tab;
	cout << endl;
	list.print();
#endif // SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR

#ifdef ITERATORS_CHECK

	List list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	cout << delimeter;
	cout << "Iterator:\n" << endl;
	for (List::Iterator it = list.begin(); it != list.end(); it++)
		cout << *it << tab;
	cout << endl;

	cout << delimeter;
	list.print_reverse();

	cout << delimeter;
	cout << "ReverseIterator:\n" << endl;
	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); it++)
		cout << *it << tab;
	cout << "\n" << endl;

	cout << delimeter;
	List list2(list);     // CopyConstructor
	list2.print();

	cout << delimeter;
	List list3;
	list3 = list;         // CopyAssignment
	list3.print();


#endif // ITERATORS_CHECK

#ifdef COPY_METHODS_CHECK

	List<int> list1 = { 3, 5, 8, 13, 21 };
	list1.print();
	List<int> list2 = { 1, 2, 4, 6 };
	list2.print();

	List<int> list3;
	list3 = list1 + list2;
	list3.print();
	cout << delimeter;
	list3.print_reverse();

#endif // COPY_METHODS_CHECK

#ifdef TEMPLATES_CHECK

	List<int> i_list = { 3,5,8,13,21 };
	i_list.print();
	
	List<double> d_list = { 2.5, 3.14, 5.2, 8.3 };
	d_list.print();

	List<string> s_list = { "What", "can", "I", "do" };
	for (string i : s_list)cout << i << tab;
	cout << endl;

	for (List<string>::Iterator it = s_list.begin(); it != s_list.end(); it++)
		cout << *it << tab;
	cout << endl;

	for (List<string>::ReverseIterator it = s_list.rbegin(); it != s_list.rend(); it++)
		cout << *it << tab;
	cout << endl;

#endif // TEMPLATES_CHECK

}