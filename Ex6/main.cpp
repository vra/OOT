#include "std_lib_facilities.h"
#include "Bargraph.h"

using namespace Graph_lib;

int main()
{
	Simple_window win(Point(0,0),1500,800,"Canvas #1");
	BarGraph bargraph1(Point(200,200),600,320);
	//BarGraph bargraph1(Point(20,20),600,320);
	//BarGraph bargraph1(Point(200,200),300,400);
	bargraph1.SetXLabel("Month");
	bargraph1.SetYLabel("C");

	
	bargraph1.ReadData("input.txt");

	win.attach(bargraph1);



	
	win.wait_for_button();
	
}