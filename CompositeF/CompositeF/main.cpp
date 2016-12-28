//
//  main.cpp
//  Composite
//  Copyright © 2016年 孙晓彤. All rights reserved.
//


#include "Composite.hpp"
#include <iostream>

using namespace std;

int main()
{
    //创建文件夹1并添加文件夹1_1和1_2到文件夹1下
    ConcreteComposite folder1("2016照片集");
    ConcreteComposite folder1_1("2016.5");
    ConcreteComposite folder1_2("2016.7");
    folder1.attach(&folder1_1);
    folder1.attach(&folder1_2);
    
   //创建文件夹1_3并添加文件1_3_1和1_3_2到文件夹1_3下
    ConcreteComposite folder1_3("2016.11");
    Picture file1_3_1("2016.11.1");
    Picture file1_3_2("2016.11.2");
    folder1_3.attach(&file1_3_1);
    folder1_3.attach(&file1_3_2);
    
    //将文件夹1_3添加到文件夹1下
    folder1.attach(&folder1_3);
    
    string str("+ ");
    folder1.display(str);
    cout<<endl;
    folder1_3.detach(&file1_3_1);
    folder1.display(str);
    
    
    cout<<endl;
    folder1.detach(&folder1_3);
    folder1.display(str);
    return 0;
}


