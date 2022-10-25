#include"function.h"
#include"process.h"

int main()
{
	Interface interface;
	Function function;

	//构建界面
    interface.Make();
	//进行游戏
	while(function.CarryOut(interface));
	//回收界面
	interface.Clear();

	return 0;

}
