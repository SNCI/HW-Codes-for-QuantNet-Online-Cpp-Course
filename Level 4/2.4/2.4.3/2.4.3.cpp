//Test programme for the new constructor and assignment operater
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

void main()
{
	//The following code would not trigger compiler error without "explicit"
	/*Point p(1.0, 1.0);
	if (p==1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
	*/
	//With "explicit", the above code trigger error C2071: illegal storage class, 
	//and error C2678: "==" no operator found wich takes a left-hand operand of type 'Point'

	//The following code works properly
	Point p(1.0, 1.0);
	if (p==(Point)1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
}