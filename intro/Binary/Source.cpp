#include<iostream>
#include<cstdlib>
using namespace std;

class Binary
{
	int bin;
public:
	int get_bin()const
	{
		return bin;
	}

	void set_bin(int bin)
	{
		
	}
	//      Constructors
	Binary()
	{
		this->bin = 0;
		cout << "Default Constructor:\t  " << this << endl;
	}
	Binary(int bin)
	{
		this->bin = bin;		
		cout << "1argConstructor:\t" << this << endl;
	}
	~Binary()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//        Operators
	
	//        Methods
	void print()
	{
		cout << bin << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "");
	Binary A(1000);
	A.print();
}