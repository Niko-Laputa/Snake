#ifndef _PROCESS_ 
#define _PROCESS_

#include<vector>
#include<string>
#include"point.h"

using std::vector;
using std::string;


//蛇类
#define UP 0
#define DOWN 1 
#define LEAFT 2
#define RIGHT 3

typedef int MoveType;

class Snake
{
	
	public:
		//构造函数
		Snake();
		//读取蛇第n部分的坐标
		Point Position(int n){return position[n];}
		//蛇总共的长度
    	int Number(){return position.size();}
		//运动后蛇头应在的位置
		Point NextHead();
		//蛇进行移动
    	void Move();
		//蛇的添加运动
		void AddMove();
		//改变蛇的运动方向
    	void SetMove(char operate);
	private:
		//存储蛇位置的坐标
    	vector<Point> position;
		//蛇头的运动方向
    	MoveType move;

};

//地图类
#define DEFAULTW 12
#define DEFAULTL 35
#define EMPTY 0
#define SEMPTY " "
#define WELL 1
#define SWELL "*"
#define SNAKE 2
#define SSNAKE "o"
#define SNAKE_HEAD 3
#define SSNAKE_HEAD "@"
#define ADDSNAKE 4
#define SADDSNAKE "#"

typedef string MapType;

class Map
{
	public:   
		//默认构造函数
		Map();
		//自定义地图面积的构造函数
		Map(int new_length,int new_width);
		//读取坐标信息
		MapType Read(Point point);
		//修改坐标为新类型
		int RevisePoint(Point point,int type);
		//蛇普通移动时地图的变化
        void Move(Snake snake);
		//蛇添加移动时地图的变化
	    void AddMove(Snake snake);
		//读取宽度
		int Width(){return width;}
		//读取长度
        int Length(){return length;}
		//创建随机点
		Point Rand();
	private:
		//地图长度
		int length;
		//地图宽度
		int width;
		//存储地图信息
		vector<vector<int>> map;
		//初始化墙壁
		void Well();

};

#endif //_PROCESS_
