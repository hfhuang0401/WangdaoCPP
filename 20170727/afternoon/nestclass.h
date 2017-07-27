#ifndef __NESTCLASS_H__
#define __NESTCLASS_H__

#include <iostream>

using std::cout;
using std::endl;

//PIMPL设计模式
//1.实现信息隐藏
//2.只要接口稳定，内部的实现做任何变化，都不会影响使用该头文件的程序
//3.减少编译的依赖


class Line
{
public:
	Line(int,int,int,int);
	~Line();
	void printLine()const;

private:
	class LineImpl;
	LineImpl * _pImpl;
};


#endif
