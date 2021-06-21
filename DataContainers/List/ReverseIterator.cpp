#include"ReverseIterator.h"
template<typename T>  List<T>::ReverseIterator::ReverseIterator(Element* Temp) :BaseIterator(Temp)
{
#ifdef DEBUG
	cout << "RIConstructor:\t\t" << this << endl;
#endif // DEBUG

}
template<typename T> List<T>::ReverseIterator::ReverseIterator::~ReverseIterator()
{
#ifdef DEBUG
	cout << "RIDestructor:\t\t" << this << endl;
#endif // DEBUG
}
template<typename T>typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator++()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ReverseIterator List<T>::ReverseIterator::operator++(int)
{
	ReverseIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ReverseIterator& List<T>::ReverseIterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ReverseIterator List<T>::ReverseIterator::operator--(int)
{
	ReverseIterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}

