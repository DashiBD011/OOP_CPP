#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n----------------------------------------------------------\n"

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
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()const
	{
		return Root;
	}
	Element* getLeft()const
	{
		return Root->pLeft;

	}
	Element* getRight()
	{
		return Root->pRight;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(Element* Root)
	{
		this->Root = Root;
	}
	~Tree()
	{
#ifdef DEBUG
#endif // DEBUG
		cout << "TDestructor:\t" << this << endl;

	}
	
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
	
	int max_value(Element* Root)
	{
		return Root->pRight ? max_value(Root->pRight) : Root->Data;
	
	}
	int min_value(Element* Root)
	{
		if (Root->pLeft == nullptr)return Root->Data;
		else return min_value(Root->pLeft);

	}
	int count(Element* Root)
	{
		return Root ? count(Root->pLeft) + count(Root->pRight) + 1 : 0;
	}
	int sum(Element* Root)
	{
		return Root ? sum(Root->pLeft) +  sum(Root->pRight) + Root->Data : 0;
		
	}
	double avg()
	{
		return (double)sum(this->Root) / count(this->Root);
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
	 
	////////////////////////////////////
	//ничего лучше я не смог придумать//

	void insert2(int Data)
	{
		insert(Data, this->Root);
	}
	int min_value2()
	{
		return min_value(this->Root);
	}
	int max_value2()
	{
		return max_value(this->Root);
	}
	int count2()
	{
		return count(this->Root);
	}
	int sum2()
	{
		return sum(this->Root);
	}
	void print2()
	{
		print(this->Root);
	}
	

};

class UniqueTree :public Tree
{
public:
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
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;

	for (int i = 0; i < n; i++)
	{
		tree.insert2(rand()%10);
	}
	tree.print2();
	cout << endl;
	cout << "Минимальное значение в дереве:  " << tree.min_value2() << endl;
	cout << "Максимальное значение в дереве: " << tree.max_value2() << endl;
	cout << "Количество элементов дерева:    " << tree.count2() << endl;
	cout << "Сумма всех элементов дерева:    " << tree.sum2() << endl;
	cout << "Среднее арифметическое элементов дерева: " << tree.avg() << endl;

	cout << delimeter;
	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 10, u_tree.getRoot());
	}
	u_tree.print(u_tree.getRoot());
	cout << endl;
	cout << "Количество элементов дерева: " << u_tree.count(u_tree.getRoot()) << endl;
}
