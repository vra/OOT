#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char buffer[256];
	ifstream  file1("a.txt",ios::in|ios::out);//如果增加ios：：ate则不能读入file3中
	ifstream  file2("b.txt",ios::in|ios::out);
	ofstream file3("d://c.txt",ios::in|ios::out);//可以任意设置路径

	if(file1.is_open() && file2.is_open() && file3.is_open())
	{
		file1.getline(buffer,100);
		//cout<<buffer<<endl;
		file3<<buffer;
		file3<<",";

		file2.getline(buffer,100);
		//cout<<buffer<<endl;
		file3<<buffer;
			
		file1.close();
		file2.close();
		file3.close();

		cout<<"操作完成\n";

		char keep=' ';
		cin>>keep;

	}

}