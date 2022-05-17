#include "SetIterator.h"
#include "Set.h"
#include <exception>

//Complexity: O(m)
SetIterator::SetIterator(const Set& m) : set(m)
{
    current_it=0;
    while(set.table.T[current_it]==NULL_TELEM || set.table.T[current_it]==DELETED)
        current_it++;
}

//Complexity: O(m)
void SetIterator::first() {
	current_it=0;
    while(set.table.T[current_it]==NULL_TELEM || set.table.T[current_it]==DELETED)
        current_it++;
}

//Complexity: O(m)
void SetIterator::next() {
    if (this->valid()==false)
        throw std::exception();
    current_it++;
    while(set.table.T[current_it]==NULL_TELEM || set.table.T[current_it]==DELETED)
        current_it++;
}

//Complexity: tetha(1)
TElem SetIterator::getCurrent()
{
    if (this->valid()==false)
        throw std::exception();
	return set.table.T[current_it];
}
//Complexity: tetha(1)
bool SetIterator::valid() const {

    if (set.isEmpty())
        return false;
    if(current_it<set.table.m)
        return true;
	return false;
}



