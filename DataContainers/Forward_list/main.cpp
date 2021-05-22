#include<iostream>
using namespace std;

class Element
{
	int Data;        // �������� ��������
	Element* pNext;  // ��������� �� ��������� ������� 
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t"<< this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count = 0; // ������������� ����������� ����������

class ForwardList
{
	Element* Head;
	int size;
public:
	ForwardList() 
	{
		Head = nullptr; //DefaultConstructor ������� ������ ������
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//        Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New -> pNext = Head;
		Head = New;
		size++;
	}

	void push_back(int Data)
	{
		// push_back �� ����� �������� � ������ �������
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
		size++;
	}

	//        Erasing elements:
	void pop_front()
	{
		Element* Temp = Head;
		Head = Temp->pNext;
		delete Temp;
		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(int Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
	    if (Temp == nullptr)break;
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	//        Methods
	void print()
	{
		Element* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
		cout <<"���������� ��������� � ������: "<< size << endl;
		cout <<"����� ���������� ���������: "<< Element::count << endl;

	} 
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	//list.pop_front();
	//list.print();
	//list.pop_back();
	//list.print();
	////list.push_back(1000);
	int value;
	int index;
	cout << "������� ����������� ��������: "; cin >> value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	list.insert(value, index);
	list.print();
	cout << "��� ���� ������:\n" << endl;
	ForwardList list2;
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(8);
	list2.print();
}