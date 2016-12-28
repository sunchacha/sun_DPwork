//
//  main.cpp
//  UndoRedoF
//  Copyright © 2016年 孙晓彤. All rights reserved.
//模拟寝室的留言板，白板上仅显示最新的留言内容

#include "Command.hpp"


int main()
{
    
    Commander *p = new Commander( new InputCommand( "无人留言状态" ) );

    p->ExecuteCommand( new InputCommand( "求七点开热水器" ) );
    p->ExecuteCommand( new InputCommand( "数据库课本能帮我带一下么" ) );
    p->ExecuteCommand( new InputCommand( "啊中午去吃火锅吧！" ) );
    
    p->Undo();
    p->Undo();
    p->ExecuteCommand( new InputCommand( "今晚我不回寝室了" ) );
    p->Undo();
    p->Undo();
    
    //执行失败,undo 到最原始情况
    p->Undo();
    
    p->Redo();
    p->Redo();
    p->Redo();
    
    p->ExecuteCommand( new InputCommand( "这周二的课不用上了" ) );
    
    p->Undo();
    p->Redo();
    p->Redo();
    
    //执行失败,redo 到最新情况
    p->Redo();
    delete p;
    return 0;
}
