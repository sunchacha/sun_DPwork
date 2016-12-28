//
//  Composite.hpp
//  Composite
//  Copyright © 2016年 孙晓彤. All rights reserved.
//

#ifndef Composite_hpp
#define Composite_hpp


#include <list>
#include <string>
#include <iostream>
using namespace std;

class Composite
{
public:
    Composite(const char* name):mName(name){}
    virtual void attach(Composite* file_name){}
    virtual void detach(Composite* file_name){}
    virtual void display(string str){}
    const char* mName;
    
protected:
    list<Composite* > mList;
};

class ConcreteComposite:public Composite{
public:
    ConcreteComposite(const char* name):Composite(name){}
    virtual void attach(Composite* file_name);
    virtual void detach(Composite* file_name);
    virtual void display(string str);
};

class Picture:public Composite{
public:
    Picture(const char* name):Composite(name){}
    virtual void display(string str);
};


#endif
