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
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
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
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
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
	cout << "������� ������ ������: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand()%100,tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "����������� �������� � ������: " << (tree.min_value(tree.getRoot())) << endl;
	cout << "������������ �������� � ������: " << (tree.max_value(tree.getRoot())) << endl;
	cout << "���������� ��������� ������: " << tree.count(tree.getRoot()) << endl;

	cout << delimeter;
	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.getRoot());
	}
	u_tree.print(u_tree.getRoot());
	cout << endl;
	cout << "���������� ��������� ������: " << u_tree.count(u_tree.getRoot()) << endl;
}
