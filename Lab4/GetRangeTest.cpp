//
// Created by arbac on 5/16/2022.
//
#include "Set.h"
#include <assert.h>
#include <iostream>
using namespace std;
void getRangeTest(){
    Set s;
    assert(s.isEmpty() == true);
    assert(s.getRange() == -1);
    assert(s.add(1)==true);
    assert(s.add(10)==true);
    assert(s.add(7)==true);
    //cout<<s.getRange()<<endl;
    assert(s.getRange()==9);
}