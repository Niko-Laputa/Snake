#include"interface.h"

//构造函数
Interface::Interface()
{
	time=800;
}

//构造界面
void Interface::Make()
{
	//初始化窗口
	initscr();
	//隐藏输入模式
	noecho();
	//无缓存模式
	cbreak();
	//定时输入模式
	timeout(time);

}

//输出地图
void Interface::InputMap(Map map)
{
    //清屏
	clear();
	
	int width=map.Width(),length=map.Length();
	Point point(0,0);
	int row=0,col=0;
	
	//光标剧中
	getmaxyx(stdscr,row,col);
	
	for(int i=0;i<width;i++)
	{
		move((row-width)/2+i,(col-length)/2);
		
		point.SetY(i);
		for(int j=0;j<length;j++)
		{
			point.SetX(j);
		    printw("%s",map.Read(point).c_str());
		}
		printw("\n");
	}
	refresh();
}

//读取操作信息
char Interface::ReadOperate()
{
    return getch();
}

//回收界面
void Interface::Clear()
{
    clear();

	int row=0,col=0;
	getmaxyx(stdscr,row,col);
	move(row/2,col/2);
	printw("Game Over!!");
	refresh();

    sleep(2);
	endwin();
}
