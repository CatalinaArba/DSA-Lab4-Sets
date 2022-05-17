#include "Set.h"
#include "SetITerator.h"
#include <math.h>
#include <iostream>
using namespace std;
//complexity tetha(1)
int Set::hash1(int k) const
{
    if (k<0)
        k*=-1;
    return k% this->table.m;
}
//complexity tetha(1)
int Set::hash2(int k) const
{
    if (k<0)
        k*=-1;

    return 1+(k%(this->table.m-1));
}
//complexity o(sqrt(n))
int Set::isPrime(int nr)
{
    for (int d=2;d<= sqrt(nr);d++)
        if (nr%d==0)
            return 0;
    return 1;
}

int Set::findFirstPrimeBiggerThenNr(int nr)
{
    nr+=1;
    while(1){
        if(this->isPrime(nr)==1)
        {
            return nr;
        }
        nr+=1;
    }
}
//Complexity: Theta(m)
void Set::resize(){
    int old_m=this->table.m;
    this->table.m= findFirstPrimeBiggerThenNr(this->table.m*2);
    //cout<< this->table.m<<endl;
    //cout<<"RESIZE"<<endl;
     TElem *newT= new TElem[this->table.m ];
    //We initialize every element from the new set with nulltelem
    for (int i = 0; i < this->table.m; i++) {
        newT[i] = NULL_TELEM;
    }
    //cout<<"face elementele null"<<endl;
    //for every element from the old set we find the new position in the new set depending on the new m
    for(int i=0;i<old_m;i++){
        if (this->table.T[i]!=NULL_TELEM&&this->table.T[i]!=DELETED) {
            int ok = 0;
            int j = 0;
            int h1 = this->hash1(this->table.T[i]);
            int h2 = this->hash2(this->table.T[i]);
            while (ok == 0) {
                int pos = (h1 + j * h2) % this->table.m;
                if (newT[pos] == NULL_TELEM) {
                    newT[pos] = table.T[i];
                    //cout<<"new pos"<<pos<<" elem:"<<table.T[i]<<endl;
                    ok = 1;
                } else
                    j++;
            }
        }
    }
    //cout<<"Genereaza noi pozitii"<<endl;
    delete[] this->table.T;
    this->table.T = newT;
}
//Complexity: Theta(1)
Set::Set() {
    this->table.m=7919;
    this->table.T= new TElem[this->table.m];
    this->nrOfElements=0;
    //we initialize all elements with null telem
    for(int i=0;i<this->table.m;i++) {
        this->table.T[i] = NULL_TELEM;
    }
}

//Complexity: O(m)
bool Set::add(TElem elem) {
    //if the set is full, we resize it
    if(nrOfElements== this->table.m)
        this->resize();
    //if the element is already in the set we return false
    if (this->search(elem))
        return false;
    //we compute the value of the hashfunction1 and hashfunction2 depending on elem
    int h1= this->hash1(elem);
    int h2= this->hash2(elem);
    int ok=0;
    int j=0;
    //we search for a free space in the set
    while(ok==0){
        int pos=(h1+j*h2)%this->table.m;
        if (this->table.T[pos]==NULL_TELEM||this->table.T[pos]==DELETED) {
            //cout<<pos<<" "<<elem<<endl;
            this->table.T[pos] =elem;
            ok=1;
        }
        else
            j++;
    }
    this->nrOfElements+=1;
    return true;
}

//Complexity: O(m)
bool Set::remove(TElem elem) {
    //if the element is not in the set we return false
	if(!search(elem))
        return false;
    //we compute the value of hash1 and hash2
    int h1= this->hash1(elem);
    int h2= this->hash2(elem);
    int i=0;
    int pos=(h1+i*h2)%this->table.m;
    while(1)
    {
        if(this->table.T[pos]==elem)
        {
            //mark elem as deleted
            table.T[pos]=DELETED;
            nrOfElements--;
            return true;
        }
        else{
            i++;
            pos=(h1+i*h2)%this->table.m;
        }
    }
}
//Complexity: O(m)
bool Set::search(TElem elem) const {
    int i=0;
    int h1= this->hash1(elem);
    int h2= this->hash2(elem);
    int pos=(h1+i*h2)%this->table.m;
    while(i<=this->table.m){
        /*if(this->table.T[pos]==NULL_TELEM||this->table.T[pos]==DELETED)
            break;*/
        if(this->table.T[pos]==elem){
            //cout<<"True i="<<i<<" pos="<<pos<<endl;
            return true;
        }

        i++;
        pos=(h1+i*h2)%this->table.m;

    }
    //cout<<"False i="<<i<<" pos="<<pos<<endl;
    return false;

}

//Complexity: Theta(1)
int Set::size() const {

	return nrOfElements;
}

//Complexity: Theta(1)
bool Set::isEmpty() const {
	if(nrOfElements==0)
        return true;
	return false;
}
//Complexity: O(m)
int Set::getRange() const{
    if (this->isEmpty())
        return -1;
    int i=0;
    while(this->table.T[i]==NULL_TELEM ||this->table.T[i]==DELETED)
        i++;
    int min=this->table.T[i];
    int max=this->table.T[i];
    for(i=0;i<this->table.m;i++)
    {
        if(this->table.T[i]!=NULL_TELEM &&this->table.T[i]!=DELETED) {
            if (this->table.T[i] < min)
                min = this->table.T[i];
            if (this->table.T[i] > max)
                max = this->table.T[i];
        }
    }
    //cout<<max<<" "<<min;
    return max-min;
}

//Complexity: Theta(1)
Set::~Set() {
	delete[] this->table.T;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


