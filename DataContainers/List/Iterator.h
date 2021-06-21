#pragma once
#include"List.h"
#include"BaseIterator.h"

template<typename T>
class List<T>::Iterator :public List<T>::BaseIterator
{
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);
};