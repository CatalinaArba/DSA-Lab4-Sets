#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "GetRangeTest.h"
#include <stack>
#include <iostream>
using namespace std;




int main() {

    getRangeTest();
    cout<<"Get Range Test done!"<<endl<<endl;
	testAll();
    cout<<"Short test done!"<<endl<<endl;
	testAllExtended();


	cout << "That's all!" << endl;
	system("pause");

}



