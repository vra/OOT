#include "../../Header/Simple_window.h"
#include "../../Header/Graph.h"
#include <iostream>
int main()
{
	using namespace Graph_lib;
	
	Vector_ref<Rectangle>rect;

	Point p1(0,0);
	Simple_window win(p1,1500,640,"Canvas");

	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
			rect.push_back(new Rectangle(Point(80*i,80*j),80,80));
			int order=rect.size();
			if(i%2==0)
			{
				if(j%2==0) 
					rect[rect.size()-1].set_fill_color(Graph_lib::Color::red);
				else 
					rect[rect.size()-1].set_fill_color(Graph_lib::Color::white);
			}
			else
			{
				if(j%2==1) 
					rect[rect.size()-1].set_fill_color(Graph_lib::Color::red);
				else 
					rect[rect.size()-1].set_fill_color(Graph_lib::Color::white);
			}
			

			win.attach(rect[rect.size()-1]);
			
		}

	
	win.wait_for_button();

	char keep;
	cin>>keep;
}
