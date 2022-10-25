#ifndef _TEST_
#define _TEST_

#include"process.h"
#include"interface.h"

//总功能类
class Function
{
	public:
		//初始化
		Function(){Interface();InitializeAdd();}
		//进行一轮操作
		int CarryOut(Interface &interface);
	private:
		//存储信息的地图
		Map map;
		//进行行为的蛇
        Snake snake;
		//记录修改信息,并判断是否可以继续进行
		int Record(Interface &interface);
		//初始化蛇的位置
		void InitializeSnake();
		//初始化添加道具
		void InitializeAdd();
		
};


#endif//_TEST_
