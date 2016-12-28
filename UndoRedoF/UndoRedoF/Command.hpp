//
//  Command.hpp
//  UndoRedoF
//  Copyright © 2016年 孙晓彤. All rights reserved.
//

#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <iostream>
#include <stack>
#include <string>

class Command
{
public:
    Command(){}
    virtual ~Command(){}
    virtual void Execute() = 0;
};


class InputCommand : public Command
{
public:
    InputCommand( const std::string input )
    {
        mInput = input;
    }
    ~InputCommand()
    {}
    void Execute()
    {
        std::cout << mInput << std::endl;
    }
    
private:
    std::string mInput;
};

class Commander
{
public:
    Commander( Command *pCmd )
    {
        mUndo.push( pCmd );
    }
    ~Commander()
    {
        while( false == mUndo.empty() )
        {
            mUndo.pop();
        }
        while( false == mRedo.empty() )
        {
            mRedo.pop();
        }
    }
    
    void ExecuteCommand( Command *pCmd )
    {
        pCmd->Execute();
        mUndo.push( pCmd );
    }
    
    void Undo()
    {
        std::cout << "-------上一条-------" << std::endl;
        if( mUndo.size() < 2 )
        {
            //无法读取上一条
            std::cout << "当前已是最早留言" << std::endl;
            return;
        }
        
        auto pCmd = mUndo.top();
        mRedo.push( pCmd );
        mUndo.pop();
        //pCmd指向最新栈顶元素
        pCmd = mUndo.top();
        pCmd->Execute();
    }
    
    void Redo()
    {
        std::cout << "-------下一条-------" << std::endl;
        if( mRedo.empty() )
        {
            //无法读取下一条
            std::cout << "当前已是最新留言" << std::endl;
            return;
        }
        
        auto pCmd = mRedo.top();
        pCmd->Execute();
        mRedo.pop();
        mUndo.push( pCmd );
    }
    
private:
    std::stack< Command* > mUndo;
    std::stack< Command* > mRedo;
};

#endif
