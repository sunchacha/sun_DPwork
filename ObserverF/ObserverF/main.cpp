//
//  main.cpp
//   ObserverF
//  Copyright © 2016年 孙晓彤. All rights reserved.
//

#include "Observer.hpp"
#include <iostream>

using namespace std;

int main()
{
    Observer* p1 = new ConcreteObserverA();
    Observer* p2 = new ConcreteObserverB();
    Observer* p3 = new ConcreteObserverA();
    
    Subject* pSubject = new ConcreteSubjectA();
    pSubject->Attach(p1);
    pSubject->Attach(p2);
    pSubject->Attach(p3);
    
    pSubject->SetState("old");
    cout << "SET STATE OLD" << endl;
    
    pSubject->Notify();
    
    cout << "-------------------------------------" << endl;
    pSubject->SetState("new");
    cout << "SET STATE NEW" << endl;
    
    pSubject->Detach(p3);
    pSubject->Notify();
    
    return 0;
}
