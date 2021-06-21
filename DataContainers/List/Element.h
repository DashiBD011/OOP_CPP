#pragma once
#include"List.h"
template<typename T>
class List<T>::Element
{

	T Data;       // �������� ��������
	Element* pNext; // ��������� �� ����. �������
	Element* pPrev; // ��������� �� ����. �������
public:
	Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
	~Element();
	friend class List<T>;


};