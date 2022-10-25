#ifndef _INTERFACE_
#define _INTERFACE_

#include"process.h"
#include"ncurses.h"
#include"unistd.h"

class Interface
{
	public:
		//构造函数
		Interface();
		//构造界面
        void Make();
		//输出地图信息
        void InputMap(Map map);
		//读取操作信息
        char ReadOperate();
		//回收界面
		void Clear();
	    //读取反应时间
		int Time(){return time;}
		//修改反应时间
		void SetTime(int new_time);
    private:
		//每一轮的反应速度
	    int time;	

};

#endif //_INTERFACE_
