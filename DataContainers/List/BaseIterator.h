#pragma once
#include"Element.h"
template<typename T>
class List<T>::BaseIterator
{
protected:
	Element* Temp;
public:
	BaseIterator(Element* Temp = nullptr);
	~BaseIterator();
	bool operator==(const BaseIterator& other)const;
	bool operator!=(const BaseIterator& other)const;
	const T& operator*()const;
	T& operator*();

};