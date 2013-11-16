/*为什么在一个自定义的图形类的draw_line里面调用Rectange，Axis等不可以而调用fl库则可以：

Window里面执行attach(graph1)函数的时候，调用graph1里面的draw函数（细节：attach只是将graph
加入到Window对象的一个vector里面，下次绘图的时候一起调用每个vector成员的draw函数），一般情况
下draw函数未重载，故调用Shape基类里面的draw，这个draw函数先是保存一些设置，然后调用draw_line，
而draw_line函数一般被派生类重载过了，故调用派生类里面的draw_line,所以graph1的draw_line里面的
代码会被执行，当执行到Rectange的构造时，与主程序里面调用不同的是，没办法调用Rectange的draw_line
函数，所以就画不出来，而fl_line则不是先是从系统的底层实实在在地画出了线而不是通过调用来实现画线的，
故它能画出线来

*/
#ifndef	BARGRAPH_H
#define BARGRAPH_H


#include"std_lib_facilities.h"
#include <Window.h>
#include <Simple_window.h>

//大小由构造参数设定，横坐标根据数据量进行缩放，纵坐标根据最大值进行缩放
struct BarGraph:Shape
{
public:
	bool ReadData(const char* file);
	void draw_lines() const;
	void SetXLabel(char* xLabel0);
	void SetYLabel(char* yLabel0);

	BarGraph(Point base,double xMax,double yMax);
	~BarGraph();

private:
	vector<double>xs;
	vector<double>ys;

	char* xLabel;
	char* yLabel;

	double xBase;
	double yBase;

	double xMax;
	double yMax;
};

#endif
