//
//  Composite.cpp
//  Composite
//  Copyright © 2016年 孙晓彤. All rights reserved.
//

#include "Composite.hpp"
#include <iostream>
using namespace std;

void ConcreteComposite::attach(Composite* cmp)
{
    if(nullptr != cmp)
    {
        mList.push_back(cmp);
    }
}

void ConcreteComposite::detach(Composite* cmp)
{
    if(nullptr != cmp)
    {
        mList.remove(cmp);
    }
    cout << "File " << cmp->mName << " is deleted" << endl;
}

void ConcreteComposite::display(string str)
{
    list<Composite* >::iterator beg = mList.begin();
    cout<<str<<mName<<endl;
    str = str + "+ ";
    for ( ; beg != mList.end(); beg++)
    {
        (*beg)->display(str);
    }
}

void Picture::display(string str)
{
    cout<<str<<mName<<endl;
}




