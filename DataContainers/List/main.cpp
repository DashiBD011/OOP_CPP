#include<iostream>
using namespace std;

#define tab "\t"
#define delimeter "\n-----------------------------------------------\n"

class List
{
	class Element
	{
		int Data;       // Значение элемента
		Element* pNext; // Указатель на след. элемент
		Element* pPrev; // Указатель на пред. элемент
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			this->pPrev = pPrev;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	};
	Element* Head;   // Указатель на начальный элемент
	Element* Tail;   // Указатель на конечный элемент
	unsigned int size;  // Размер списка
public:
	
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	/*List(initializer_list<int>il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}*/
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		
		cout << "LDestructor:\t" << this << endl; 

	}

	//               Adding elements:

	void insert_first_element(int Data)
	{
		Head = Tail = new Element(Data);
		size++;
	}

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			insert_first_element(Data);
			return;
		}
		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			insert_first_element(Data);
			return;
		}
		Tail = Tail->pNext = new Element(Data, nullptr,Tail);
		size++;
	}

	void insert(unsigned int Index, int Data)
	{
		
		if (Index > size)return;
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index == size)
		{
			push_back(Data);
			return;
		}
		
		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)	Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}
		/*Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/

		Temp = new Element(Data, Temp, Temp->pPrev);
		Temp->pPrev->pNext = Temp;
		Temp->pPrev = Temp;                          //  Неправильно работает
		size++;
	}
	
	//               Erasing elements:
	
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	
	void pop_back()
	{
		if (Head == Tail)
		{
			delete Tail;
			Head = Tail = nullptr;
			size--;
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(int Index)
	{
		if (Index > size)return;
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index == size)
		{
			pop_back();
			return;
		}

		Element* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)	Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;

	}
	//               Methods
	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;
	}

	void print_reverse()
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Количество элементов списка: " << size << endl;

	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	int value;
	int index;
	cout << "Введите размер списка:"; cin >> n;
	List list;
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

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	list.erase(index);
	list.print();
	list.print_reverse();

	
}