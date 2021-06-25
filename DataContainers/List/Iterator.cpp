#include"List.h"
#include"Iterator.h"
template<typename T> List<T>::Iterator::Iterator(Element* Temp) :BaseIterator(Temp)
{

#ifdef DEBUG
	cout << "IConstructor:\t\t" << this << endl;
#endif // DEBUG

}
template<typename T>List<T>::Iterator::~Iterator()
{
#ifdef DEBUG
	cout << "IDestructor:\t\t" << this << endl;
#endif // DEBUG


}

template<typename T>typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pNext;
	return old;
}
template<typename T>typename List<T>::Iterator& List<T>::Iterator::operator--()
{
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::Iterator List<T>::Iterator::operator--(int)
{
	Iterator old = *this;
	BaseIterator::Temp = BaseIterator::Temp->pPrev;
	return old;
}