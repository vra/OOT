//问题：文件操作没能写成函数，较繁琐

#include "../../Header/std_lib_facilities.h"
#include <fstream>
#include <iostream>
using namespace std;


char ToUp(char ch)//将小写字母转化为大写字母
{
	if(ch>='a')
		ch-=32;
	return ch;
}
bool CompareWord(string word1,string word2,int i) //a>b return true
{
	string temp;
	char a=word1[i];
	char b=word2[i];
	int len1=word1.length();
	int len2=word2.length();
	if (i==0)					//如果是首字母则需要大小写转换
	{
		a=ToUp(a);
		b=ToUp(b);
	}
	if(a>b)
		return true;
	
	else if (a==b)//当前字符相等
	{
		if(min(len1,len2)==i)//最小长度与当前i相等则无法继续比较
		{
			if(len1<len2)
				return false;
			else
				return true;
		}
		else
		{
			bool isBig=CompareWord(word1,word2,i+1);
			return isBig;
		}
	}
	else
	{
		return false;
	}
}

vector<string> SortWord(vector<string> file)//字符串列表排序
{
	string temp="";

	for (int i=0;i<file.size() &&file[i]!="";i++)
	{
		for (int j=i+1;j<file.size() &&file[j]!="";j++)
		{
			if (file[i]>file[j])//a>b
			{
				temp=file[i];
				file[i]=file[j];
				file[j]=temp;
			}
		}
	}
	
	return file;
}
int main()
{
	string buffer;
	bool existed=false;

	vector<string>orderFile1;
	vector<string>orderFile2;
	fstream  file1("d://a.txt");//默认是ios::in，如果不存在，则ios::ate和ios::app都失败,以后打开也用该形式
	fstream  file2("d://电子书/b.txt");
	fstream  file3("d://电子书/c.txt",ios::app|ios::out);//如果存在，则在尾部追加 如果不存在，则新建该文件

	for (int i=0;i<file1.left;i++)
	{
		if ((file1>>buffer)!='\0')//表示还没有读到最后一个单词
		{
			for (int i = 0; i < orderFile1.size(); i++)
				if (orderFile1[i]==buffer)
					existed=true;
			if (!existed)
				orderFile1.push_back(buffer);
			else
				existed=false;
		}
		else//对最后一个单词单独进行处理。不完善之处 =-=
		{
			for (int i = 0; i < orderFile1.size(); i++)
				if (orderFile1[i]==buffer)
					existed=true;
			if (!existed)
				orderFile1.push_back(buffer);
			else
				existed=false;
			break;
		}	
	}
	file1.close();

	//将a.txt清零。或许有可以直接使用的函数？？
	file1.open("d://a.txt");
	for (int i=0;i<25;i++)
		file1<<"       ";
	file1.close();

	//往文件1中写有序的单词
	file1.open("d://a.txt");
	orderFile1=SortWord(orderFile1);
	for (int i=0;i<orderFile1.size();i++)//将有序且无重复的单词写入文件中
		file1<<orderFile1[i]<<" ";
	file1.close();

	//对文件1的操作结束，初始化buffer和existed
	buffer="";
	existed=false;

	for (int i=0;i<file2.left;i++)
	{

		if ((file2>>buffer)!='\0')
		{
			for (int i = 0; i < orderFile2.size(); i++)
				if (orderFile2[i]==buffer)
					existed=true;
			if (!existed)
				orderFile2.push_back(buffer);
			else
				existed=false;

		}
		else
		{
			for (int i = 0; i < orderFile2.size(); i++)
				if (orderFile2[i]==buffer)
					existed=true;
			if (!existed)
				orderFile2.push_back(buffer);
			else
				existed=false;
			break;
		}

	}
	file2.close();
	file2.open("d://电子书/b.txt");
	for (int i=0;i<25;i++)
	{
		file2<<"       ";
	}
	file2.close();

	//将排列有序的单词放入文件2
	file2.open("d://电子书/b.txt");
	orderFile2=SortWord(orderFile2);
	for (int i=0;i<orderFile2.size();i++)
		file2<<orderFile2[i]<<" ";

	//消除文件1和文件2中重复的单词
	for (int i=0;i<orderFile2.size();i++)
	{
		bool alreadyin=false;
		for (int j=0;j<orderFile1.size();j++)
			if(orderFile2[i]==orderFile1[j])
				alreadyin=true;

		if (!alreadyin)
			orderFile1.push_back(orderFile2[i]);
		else
			alreadyin=false;
	}


	//对文件3进行操作
	orderFile1=SortWord(orderFile1);
	for (int i=0;i<orderFile1.size();i++)
		file3<<orderFile1[i]<<" ";

	file2.close();
	file3.close();

	cout<<"操作完成\n";
	string keep= " ";
	cin>>keep;
}