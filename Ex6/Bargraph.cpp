#include "Bargraph.h"
#include "std_lib_facilities.h"
//从文件中读取数据
bool BarGraph::ReadData(const char* file)
{
	ifstream input(file);
	double x;
	double y;
	while (input>>x>>y)
	{
		xs.push_back(x);
		ys.push_back(y);
	}
	for(int i=0;i<ys.size();i++)
		cout<<xs[i]<<" "<<ys[i]<<endl;
	return true;
}

//重载Shape类的画线函数
void BarGraph::draw_lines() const
{
	
	
	//表示最大最小值的下标
	double max=0;
	double min=0;

	double ymax=ys[0];
	double ymin=ys[0];
	for(int i=1;i<ys.size();i++)
	{
		if(ys[i]>ymax) ymax=ys[i];
			
		if(ys[i]<ymin) ymin=ys[i];
	}
		
	//柱状图之间的单位间距
	double xdelta=0.8*xMax/(3*xs.size()+1);

	//y轴量的单位量
	double ydelta=0.8*yMax/ymax;
	
	//柱状图到四边的距离
	double dx=xMax/10;
	double dy=yMax/20;

	//画柱状图
	fl_color(Color::blue);
	for(int i=0;i<ys.size();i++)
	{
		fl_rectf(xBase+dx+xdelta+3*xdelta*i,yBase+dy+0.8*yMax-ydelta*ys[i],2*xdelta,ydelta*ys[i]);

		//最大最小值标记
		if(ys[i]==ymax)
		{
			fl_color(Color::red);
			fl_draw("Max",xBase+dx+xdelta+3*xdelta*i,yBase+dy+0.8*yMax-ydelta*ys[i]);
			fl_color(Color::blue);
		}
		if(ys[i]==ymin)
		{
			fl_color(Color::red);
			fl_draw("Min",xBase+dx+xdelta+3*xdelta*i,yBase+dy+0.8*yMax-ydelta*ys[i]);
			fl_color(Color::blue);
		}
	}
	
	//画坐标轴
	fl_color(0);
	fl_line(xBase+dx,yBase+dy+0.8*yMax-0.5,xBase+dx+0.8*xMax,yBase+dy+0.8*yMax-0.5);
	fl_line(xBase+dx,yBase+dy+0.8*yMax,xBase+dx,yBase+dy);

	//x轴y轴单位
	fl_draw(xLabel,xBase+5*dx,yBase+dy+0.8*yMax+0.03*yMax);
	fl_draw(yLabel,xBase+dx,yBase+dy);
}

void BarGraph::SetXLabel(char* xLabel0)
{
	xLabel=xLabel0;
}
void BarGraph::SetYLabel(char* yLabel0)
{
	yLabel=yLabel0;
}

//左上角的点和长和宽
BarGraph::BarGraph(Point base0,double xMax0,double yMax0)
{
	xBase=base0.x;
	yBase=base0.y;
	xMax=xMax0;
	yMax=yMax0;
}

BarGraph::~BarGraph()
{
}