#include<iostream>
#include<cstdlib>
using namespace std;

class Binary
{
	int bin;
	bool check_of_bin;
public:
	int get_bin()const
	{
		return bin;
	}
	bool get_check_of_bin()
	{
		return check_of_bin;
	}
	void set_bin(int bin)
	{
		this->bin = bin;
	}
	void set_check_of_bin(bool check_of_bin)
	{
		this->check_of_bin = check_of_bin;
	}
	bool check_to_bin()
	{
		char string[9] = "";
		_itoa_s(bin, string, 10);
		for (int i = 0; i < 9; i++)
		{
			if (string[i] == '0' || string[i] == '1')
			{
				check_of_bin = true;
				return true;
			}
			else
			{
				check_of_bin = false;
				cout << "Число "<< bin <<" не двоичное" << endl;
				return false;
			}

		}
	}
	//        Constructors
	Binary()
	{
		this->bin = 0;
		cout << "Default Constructor:\t  " << this << endl;
		
	}
	Binary(int bin)
	{
		cout << "1argConstructor:\t" << this << endl;
		check_to_bin();
		if (check_of_bin) this->bin = bin;		
		
		
	}
	~Binary()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//        Operators
	
	//        Methods
	void print()
	{
		if (check_of_bin)cout << bin << endl;
	}
};

Binary operator+(Binary left, Binary right)
{
	//left.check_to_bin();
	//right.check_to_bin();
	if (left.get_check_of_bin() == right.get_check_of_bin() == 1)
	{
		
	}
}


void main()
{
	setlocale(LC_ALL, "");
	Binary A(0);
	A.print();
}