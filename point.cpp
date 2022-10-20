#include"point.h"

//默认初始化
Point::Point()
{
	x=0;
	y=0;
};

//手动初始化
Point::Point(int new_x,int new_y)
{
	x=new_x;
	y=new_y;
}

//读取横坐标
int Point::ReadX()
{
	return x;
}
//读取纵坐标
int Point::ReadY()
{
	return y;
}
//修改横坐标
int Point::SetX(int new_x)
{
    x=new_x;
	return x;
}
//修该纵坐标
int Point::SetY(int new_y)
{
	y=new_y;
	return y;
}
//修改所有坐标
Point Point::SetPoint(int new_x,int new_y)
{
    x=new_x;
    y=new_y;
	
	return *this;
}
