#include "observer.h"
 
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

int main(void)
{
	unique_ptr<Observer> obsever1(new ConcreateObserver);
	unique_ptr<Observer> obsever2(new ConcreateObserver);
	unique_ptr<Observer> obsever3(new ConcreateObserver);
	unique_ptr<Observer> obsever4(new ConcreateObserver);

	unique_ptr<Subject> subject(new ConcreateSubject);
	subject->attach(obsever1.get());
	subject->attach(obsever2.get());
	subject->attach(obsever3.get());
	subject->attach(obsever4.get());

	subject->setState(1);
	subject->detach(obsever4.get());
	cout << endl;
	subject->setState(2);
	
	return 0;
}
