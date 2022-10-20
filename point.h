#ifndef _POINT_
#define _POINT_

class Point
{
public:
	//默认初始化
	Point();
	//自定义初始化
	Point(int new_x,int new_y);
	//读取横坐标
    int ReadX();
	//读取纵坐标
    int ReadY();
	//修改横坐标
	int SetX(int new_x);
	//修改纵坐标
    int SetY(int new_y);
	//修改坐标
	Point SetPoint(int new_x,int new_y);
private:
	//横坐标
    int x;
	//纵坐标
    int y;
};

#endif //_POINT_
