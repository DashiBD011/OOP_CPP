#pragma once
#include"List.h"
template<typename T>
class List<T>::Element
{

	T Data;       // Значение элемента
	Element* pNext; // Указатель на след. элемент
	Element* pPrev; // Указатель на пред. элемент
public:
	Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
	~Element();
	friend class List<T>;


};