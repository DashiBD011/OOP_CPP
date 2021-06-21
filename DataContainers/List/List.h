#pragma once
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------------------\n"

template<typename T>
class List
{
	class Element;

	Element* Head;   // Указатель на начальный элемент
	Element* Tail;   // Указатель на конечный элемент
	unsigned int size;  // Размер списка

	class BaseIterator;
public:
	class Iterator;
	class ReverseIterator;

	size_t getSize()const;
	Iterator begin();
	const Iterator begin()const;
	Iterator end();
	const Iterator end()const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	List();
	explicit List(int size);
	List(const initializer_list<T>& il);
	List(const List<T>& other);
	List(List<T>&& other);
	~List();

	//               Operators:
	T& operator[](size_t Index);
	List<T>& operator=(const List<T>& other);
	List<T>& operator=(List<T>&& other);

	//               Adding elements:
	void insert_first_element(T Data);
	void push_front(T Data);
	void push_back(T Data);
	void insert(unsigned int Index, T Data);

	//               Erasing elements:
	void pop_front();
	void pop_back();
	void erase(int Index);

	//               Methods
	void print();
	void print_reverse();
};
