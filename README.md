# Snake
一个简单的通过C++实现的贪吃使游戏，带有详细的注释。

# 编译方法
在实现贪吃蛇时，使用了ncurses库，需要进行连接

``g++ *.cpp *.h -o snake -lncurses``

#文件的说明

main.cpp文件是main函数所在文件。

function.cpp文件是逻辑模块所在文件。

function.h和process.h文件是地图和蛇类的声明。

interface.h,interface.cpp文件是界面类的声明和定义。
