#include"function.h"
#include"interface.h"
#include"process.h"

//进行一回合
int Function::CarryOut(Interface &interface)
{
	//打印地图
	interface.InputMap(map);
	//读取输入
	char operate=interface.ReadOperate();
	//改变蛇的状态
    snake.SetMove(operate);
	//记录修改信息,并判断是否退出
    if(!Record(interface))
	{
		return 0;
	}
	return 1;
}

//判断是否可以进行并进行修改
int Function::Record(Interface &interface)
{
	int judge=0;
	//读取蛇头下一步位置的地图信息
	Point head=snake.NextHead();
	MapType type=map.Read(head);

	//判断蛇应进行的行为,地图的修改应在蛇修改之前。
    if(type==SWELL||type==SSNAKE){judge=0;}
	else if(type==SEMPTY)
	{
		judge=1;
		map.Move(snake);
		snake.Move();
	}
	else if(type==SADDSNAKE)
	{
        judge=1;
		map.AddMove(snake);
		snake.AddMove();
		InitializeAdd();
		
		int time=interface.Time();
		if(time>=10)
		{
			interface.SetTime(time-10);
		}
	}

	return judge;
}

//将蛇的信息初始化入地图
void Function::InitializeSnake()
{
    Point point=snake.Position(0);
	int number=snake.Number();
    
	map.RevisePoint(point,SNAKE_HEAD);

    for(int count=1;count<number;count++)
	{
        point=snake.Position(count);
		map.RevisePoint(point,SNAKE);
	}

}
//初始化添加道具
void Function::InitializeAdd()
{
    //获取随机点
	Point point=map.Rand();
	//添加入地图
    map.RevisePoint(point,ADDSNAKE);

}

//蛇的状态类

//构造函数
Snake::Snake()
{
	//默认运动方向
	move=RIGHT;

	//默认长度和位置
    Point point1(1,1),point2(2,1),point3(3,1),point4(4,1);
    position.push_back(point4);
	position.push_back(point3);
	position.push_back(point2);
	position.push_back(point1);
}

//运动后蛇头应在的位置
Point Snake::NextHead()
{
    Point next_point=Position(0);
	int x=next_point.ReadX(),y=next_point.ReadY();
	switch(move)
	{
		case UP: next_point.SetY(y-1); break;
		case DOWN: next_point.SetY(y+1); break;
		case LEAFT: next_point.SetX(x-1); break;
		case RIGHT: next_point.SetX(x+1); break;
	}

	return next_point;
}

//改变蛇的运动方向
void Snake::SetMove(char operate)
{
	int new_move;
	//操作词转化为蛇的运动方向
	switch(operate)
	{
        case 'w':new_move=UP;break;
		   
		case 's':new_move=DOWN;break;

		case 'a':new_move=LEAFT;break;

		case 'd':new_move=RIGHT;break;

		//暂停
	    case ' ':getchar();break;
	}
	//判断蛇的运动方向是否返回上一次的位置。
	switch(new_move)
	{
		case UP:
			if(move!=DOWN)
			{move=new_move;}
			break;
		case DOWN:
			if(move!=UP)
			{move=new_move;}
			break;
		case LEAFT:
			if(move!=RIGHT)
			{move=new_move;}
			break;
		case RIGHT:
			if(move!=LEAFT)
			{move=new_move;}
			break;
	}

}

//蛇进行移动
void Snake::Move()
{
	//获取蛇头的位置
	Point head=NextHead();

    //进行移动
    position.pop_back();
	position.insert(position.begin(),head);
}

//蛇进行添加运动
void Snake::AddMove()
{
	//获取蛇头的位置
	Point head=NextHead();

    //进行移动
	position.insert(position.begin(),head);
	
}

//地图类

//默认构造函数
Map::Map()
{
	//初始化地图的长和宽
	length=DEFAULTL;
    width=DEFAULTW;
	//初始化地图信息
	vector<int> temp1(length,0);
	vector<vector<int>> temp2(width,temp1);
	map=temp2;
	//初始化墙壁
	Well();
}

//自定义地图面积的构造函数
Map::Map(int new_length,int new_width)
{
	length=new_length;
	width=new_width;
	//初始化地图信息
	vector<int> temp1(length,0);
	vector<vector<int>> temp2(width,temp1);
	map=temp2;
	//初始化墙壁
	Well();
}

//初始化墙壁
void Map::Well()
{
    Point point;

    for(int i=0;i<length;i++)
	{
		point.SetX(i); 
		RevisePoint(point,WELL);
	}

	for(int i=1;i<width;i++)
	{
        point.SetY(i);
		point.SetX(0);
		RevisePoint(point,WELL);
		point.SetX(length-1);
		RevisePoint(point,WELL);
	}

	point.SetY(width-1);
    
    for(int i=0;i<length;i++)
	{
		point.SetX(i); 
		RevisePoint(point,WELL);
	}	
}
//读取坐标信息
MapType Map::Read(Point point)
{
	int x=point.ReadX(),y=point.ReadY();
    string input;
    switch(map[y][x])
	{
	    case WELL: input=SWELL;break;

        case EMPTY: input=SEMPTY;break;

		case SNAKE_HEAD: input=SSNAKE_HEAD;break;

		case SNAKE: input=SSNAKE;break;

		case ADDSNAKE: input=SADDSNAKE;break;
    }

	return input;
}
//修改坐标信息
int Map::RevisePoint(Point point,int type)
{
    int x=point.ReadX(),y=point.ReadY();
	map[y][x]=type;

	return type;

}
//蛇普通移动时地图的变化
void Map::Move(Snake snake)
{
    int number=snake.Number();
	Point new_head=snake.NextHead(),end=snake.Position(number-1),old_head=snake.Position(0);
    
	RevisePoint(new_head,SNAKE_HEAD);
	RevisePoint(old_head,SNAKE);
	RevisePoint(end,EMPTY);
}
//蛇添加运动后地图的变化
void Map::AddMove(Snake snake)
{
    int number=snake.Number();
	Point point=Rand();
	Point new_head=snake.NextHead(),end=snake.Position(number-1),old_head=snake.Position(0);
    
	RevisePoint(new_head,SNAKE_HEAD);
	RevisePoint(old_head,SNAKE);

	//添加障碍
	RevisePoint(point,WELL);
}
//创建随机点
Point Map::Rand()
{
	Point point(0,0);
    
	while(Read(point)!=SEMPTY)
	{
	    point.SetX(rand()%length);
		point.SetY(rand()%width);
	}

	return point;
}
