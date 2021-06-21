#pragma once
#include"List.h"
#include"BaseIterator.h"

template<typename T>
class List<T>::ReverseIterator :public List<T>::BaseIterator
{
public:
	ReverseIterator(Element* Temp = nullptr);
	~ReverseIterator();
	ReverseIterator& operator++();
	ReverseIterator operator++(int);
	ReverseIterator& operator--();
	ReverseIterator operator--(int);


};
