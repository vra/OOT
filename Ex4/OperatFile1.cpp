#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char buffer[256];
	ofstream  file1("a.txt",ios::in|ios::out|ios::ate);
	ifstream  file2("b.txt",ios::in|ios::out);

	if(file1.is_open() && file2.is_open())
	{
		file1<<",";
		file2.getline(buffer,100);
		//cout<<buffer<<endl;
		file1<<buffer;
			
		file1.close();
		file2.close();

		char keep=' ';
		cin>>keep;

	}

}