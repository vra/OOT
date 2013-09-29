//存在的问题：
//Problem1:当输入错误时，不能继续输入，只能关闭，前面输入的数据都无法保持
//Problem2:分隔符不能用空格 回车等
#include <iostream>
#include <vector>
#include "std_lib_facilities.h"

using namespace std;

vector<string>names;
vector<int>scores;
			
						
//判断是否有重名，有则返回true，否则返回false t
bool IsDefined(int c,string name)
{
	if(c==0)
		return false;

	for(int i=0;i<c;i++)
		if(names[i]==name)
			return true;

	return false;
};
int main()
{
	
	char selectedSparators=':';			//分隔符
	string inStr;					//暂存输入的字符串
	int	inScore;				//暂存输入的年龄
	int count=0;					//记录当前输入的数据的个数
	string keep;					//为了保持窗口常开的字符串


	cout<<"Enter name and score(if end all,input \"No more\")\n";//---------------------------------Problem1
	cin>>inStr;

	while (inStr!="No")	
	{
		try
		{
		
		if(IsDefined(count,inStr))
		{
			throw inStr;

		}
		}catch(string inStr)
		{
			cin>>keep;				//为了保持窗口打开状态，这句和下面的cin语句都不能省，不知道为什么
			cout<<"The name \""<<inStr<<"\" existed";
			cin>>keep;
		}
		cin>>inScore;
		names.push_back(inStr);
		scores.push_back(inScore);
		count++;
		cin>>inStr;
	}
	string afterNo;
	cin>>afterNo;
	if(afterNo=="more")
	{
		if(count!=0)
		{
		cout<<"Enter your separator(You can choose ':' , ' ' , tab or any other characters)\n";
		cin>>selectedSparators;									//--------------------------------------Problem2

		cout<<"name\tseparator\tscore\n";							//当字符长度超出一个tab空间的长度时，自动增加一个或多个tab空间

		for(int i=0;i<count;i++)
			cout<<names[i]<<"\t"<<selectedSparators<<"\t\t"<<scores[i]<<endl;

		cin>>inStr;												//keep console keep
		}
		else
		{
			cout<<"There is no data to display";
			cin>>keep;
		}
	}
	else 
	{
		cout<<"Input error.Do you mean \"No more\"?";
		cin>>keep;
	}
}
