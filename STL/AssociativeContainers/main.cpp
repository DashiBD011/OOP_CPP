#include<iostream>
#include<map>
#include<unordered_map>
#include<list>

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n--------------------------------------\n"

//#define STL_MAP
#define DICTIONARY
void main()
{
	setlocale(LC_ALL, "");

#ifdef STL_MAP
	// map - ��� ���������, ������� ������ ������� � ���� ��������� ������
	// ������ ��������� map �������� ���� "���� - ��������"
	// ����� �������� �����������, �� ���� � ����� map �� ����� ���� 2� ���������
	// � ����������� �������, ���� �������� ����� �����������
	// Multimap ��������� ������� ��� � ����� ���������� �����.

	std::unordered_multimap<int, std::string>week =
	{
		std::pair<int,std::string>(5,"Friday"),
		std::pair<int,std::string>(2,"Tuesday"),
		std::pair<int,std::string>(4,"Thursday"),
		std::pair<int,std::string>(5,"Friday"),
		std::pair<int,std::string>(3,"Wednesday"),
		std::pair<int,std::string>(6,"Saturday"),
		std::pair<int,std::string>(0,"Sunday"),
		std::pair<int,std::string>(5,"Friday"),
		std::pair<int,std::string>(7,"Sunday")
	};
	//week[7] = "�����������";
	for (std::unordered_multimap<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab;  //first - key
		cout << it->second << endl;//second - value
	}
	cout << endl;

#endif // STL_MAP

#ifdef DICTIONARY
	std::map<std::string, std::list<std::string>>dictionary =
	{
		std::pair<std::string,std::list<std::string>>("Hello",{"������", "�������"}),
		std::pair<std::string,std::list<std::string>>("Space",{"������", "������������", "������"}),
		std::pair<std::string,std::list<std::string>>("Definition",{"�����������"}),
		std::pair<std::string,std::list<std::string>>("Claim",{"���������", "�������� � ����� ������"}),
		std::pair<std::string,std::list<std::string>>("Tie",{"�����", "�������"})
	};
	for (std::map<std::string, std::list<std::string>> ::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << ":";
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			cout << *jt << ",";
		}
		cout << endl;
	}
#endif // DICTIONARY


}