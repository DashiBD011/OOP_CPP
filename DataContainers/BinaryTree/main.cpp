#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
#define tab "\t"
#define delimeter "\n----------------------------------------------------------\n"
//#define DEBUG


class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;

#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;

#endif // DEBUG
		}
		bool is_leaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()const
	{
		return Root;
	}
	
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	
	Tree(const initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			insert(*it,Root);
		}
	}
	Tree(const Tree& other):Root()
	{
		copy(other.Root);

#ifdef DEBUG
		cout << "CopyConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Tree()
	{
#ifdef DEBUG
		cout << "TDestructor:\t" << this << endl;
#endif // DEBUG
		clear();

	}

	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void erase(int Data)
	{
		erase(Data, this->Root);
	}
	void clear()
	{
		clear(Root);
		this->Root = nullptr;
	}
	int min_value()const
	{
		return min_value(this->Root);
	}
	int max_value()const
	{
		return max_value(this->Root);
	}
	int count()const
	{
		return count(this->Root);
	}
	int sum()const
	{
		return sum(this->Root);
	}
	double avg()const
	{
		return (double)sum(this->Root) / count(this->Root);
	}
	void print()const
	{
		print(this->Root);
		cout << endl;
	}

	Tree& operator=(const Tree& other)
	{
		if (this == &other)return *this;
		clear(Root);
		copy(other.Root);
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

private:

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			/*if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);*/
			if (Root->pLeft)insert(Data, Root->pLeft);
			else Root->pLeft = new Element(Data);
			
		}
		else
		{
			/*if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);*/
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}
	
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (count(Root->pLeft) > count(Root->pRight))
				{
					Root->Data = max_value(Root->pLeft);
					erase(max_value(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = min_value(Root->pRight);
					erase(min_value(Root->pRight), Root->pRight);
				}
			}
		}
		
		
	}

	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	int max_value(Element* Root)const
	{
		return Root->pRight ? max_value(Root->pRight) : Root->Data;
	
	}

	int min_value(Element* Root)const
	{
		if (Root->pLeft == nullptr)return Root->Data;
		else return min_value(Root->pLeft);

	}

	int count(Element* Root)const
	{
		return Root ? count(Root->pLeft) + count(Root->pRight) + 1 : 0;
	}

	int sum(Element* Root)const
	{
		return Root ? sum(Root->pLeft) +  sum(Root->pRight) + Root->Data : 0;
		
	}
	
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}

	void copy(Element* Root)
	{
		if (Root == nullptr)return;
		insert(Root->Data,this->Root);
		copy(Root->pLeft);
		copy(Root->pRight);
	}
	 
};

class UniqueTree :public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			/*if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);*/
			if (Root->pLeft)insert(Data, Root->pLeft);
			else Root->pLeft = new Element(Data);

		}
		if(Data>Root->Data)
		{
			/*if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);*/
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
};

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;

	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве:  " << tree.min_value() << endl;
	cout << "Максимальное значение в дереве: " << tree.max_value() << endl;
	cout << "Количество элементов дерева:    " << tree.count() << endl;
	cout << "Сумма всех элементов дерева:    " << tree.sum() << endl;
	cout << "Среднее арифметическое элементов дерева: " << tree.avg() << endl;

	cout << delimeter;
	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 10);
	}
	u_tree.print();
	cout << endl;
	cout << "Количество элементов дерева: " << u_tree.count() << endl;

	/*Tree tree2;
	tree2 = tree;
	tree2.print();*/
	cout << delimeter << endl;
	int value;
	cout << "Введите значение удаляемого элемента: "; cin >> value;
	tree.erase(value);
	tree.print();
#endif // BASE_CHECK

	Tree tree = { 50,25,80,16,32,64,85,12,22,31,58,77,84,91 };
	tree.print();
	int value;
	cout << "Введите значение удаляемого элемента: "; cin >> value;
	tree.erase(value);
	tree.print();
	
}
