#pragma once
#include<iostream>
using namespace std;

#define tab "\t"
#define delimeter "\n-----------------------------------------------------\n"

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>
class Element
{
	T Data;        // �������� ��������
	Element<T>* pNext;  // ��������� �� ��������� ������� 
	static int count;
public:
	Element(T Data, Element<T>* pNext = nullptr);
	~Element();
	friend class ForwardList<T>;
	friend class Iterator<T>;
};
