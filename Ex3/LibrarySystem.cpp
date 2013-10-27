//问题：1 Date函数
#include <iostream>
#include <time.h>
#include "std_lib_facilities.h"
#define MaxSizeOfNameSpace 1000

//日期类
class  Date
{
public:
	Date(int theYear,int theMonth,int theDay)
	{
		year=theYear;
		month=theMonth;
		day=theDay;
	};

	Date()
	{
		time_t now=time(0);//注意一定要初始化
		tm *tm1=localtime(&now) ;

		day=tm1->tm_mday;
		year=tm1->tm_year+1900;
		month=tm1->tm_mon+1;
	}
	int GetYear()
	{
		return year;
	}
	int GetMonth()
	{
		return month;
	}
	int GetDay()
	{
		return day;
	}
private:
	int year;
	int month;
	int day;
};
class OwedName
{
public:
	string name;
	OwedName()
	{
	}
	//显示欠费学生名字
	void DisplayInfo()
	{
		cout<<"姓名：\t"<<name<<endl;
	}
};

 class Book
{
private:
	string ISBNNum;
	string name;
	string author;
	string pblsDate;
	bool  isOut;

public:

	//显示信息
	void DisplayInfo()
	{
		cout<<"图书信息------------------------------"<<endl;
		cout<<"ISBN号：\t"<<ISBNNum<<endl;
		cout<<"书名：\t\t"<<name<<endl;
		cout<<"作者：\t\t"<<author<<endl;
		cout<<"出版日期：\t"<<pblsDate<<endl;
		cout<<"是否借出：\t";
		if(isOut)
			cout<<"已借出"<<endl;
		else
			cout<<"未借出"<<endl;
		cout<<endl;
	}
	string GetISBNNum()
	{
		return ISBNNum;
	}

	string GetName()
	{
		return name;
	}
	string GetAuthor()
	{
		return author;
	}
	string GetDat()
	{
		return pblsDate;
	}
	bool GetIsOut()
	{
		return isOut;
	}
	void LendOut()
	{
		isOut=true;
	}
	void ReturnIn()
	{
		isOut=false;
	}
	Book()
	{
	}
	bool DateFormat1(string & date)//20130908
	{
		bool allIsNum=true;
		//1.检查全是数字
		for(int i=0;i<8;i++)
			if(date[i]>'9' ||date[i]<'0')
				allIsNum=false;
		if(!allIsNum)
		{
			cout<<"日期格式有错误"<<endl;
			return false;
		}

		//2.检查日期格式
		char year0=date[0];
		char year1=date[1];
		char year2=date[2];
		char year3=date[3];
		int year=(year0-48)*1000+(year1-48)*100+(year2-48)*10+(year3-48);

		char month0=date[4];
		char month1=date[5];
		int month=((int)month0-48)*10+((int)month1-48);
		
		char day0=date[6];
		char day1=date[7];
		int day=((int)day0-48)*10+((int)day1-48);

		switch(month)
		{
		case 0:
			return false;
			break;
		case 1:case 3:case 5:case 7:case8 :case 10:case 12:
			if(day>31 || day<1)
				return false;
			else 
				return true;
			break;
		case 4:case 6:case 9:case 11:
			if(day>30 || day<1)
				return false;
			else 
				return true;
			break;
		case 2:
			if(year%4!=0 ||(year%4==0 && year%400!=0))
			{
				if(day>28 || day<1)
					return false;
				else 
					return true;
			}
			else
			{
				if(day>29 || day<1)
					return false;
				else 
					return true;
			}
			break;
		default:
			return false;
			break;

		}

			
	}
	bool DateFormat2(string date)
	{
		return true;
	}
	Book(string theISBNNum,string theName,string theAuthor,string theDate)
	{
		//ISNB格式检查
		if(theISBNNum.length()<6)
		{
			cout<<"ISBN码输入格式有误"<<endl;
			return;
		}
		if((int)theISBNNum[0]<'0' || (int)theISBNNum[0]>'9'
			|| (int)theISBNNum[2]<'0' || (int)theISBNNum[2]>'9'
			||(int)theISBNNum[4]<'0' || (int)theISBNNum[4]>'9'
			||(((int)theISBNNum[6]<'0' || (int)theISBNNum[6]>'9')
				&&((char)theISBNNum[6]>'z'||(char)theISBNNum[6]<'a')
				&&((char)theISBNNum[6]>'Z'||(char)theISBNNum[6]<'A')))
		{
			cout<<"ISBN码输入格式有误"<<endl;
			return;
		}
		
		//日期检查
		if(theDate.length()<8)
		{
			cout<<"日期输入格式有误"<<endl;
			return;
		}
		if(theDate.length()==8)
		{
			if(DateFormat1(theDate)) 
			{
				char month0=theDate[4];
				char month1=theDate[5];
				int month=((int)month0-48)*10+((int)month1-48);
		
				char day0=theDate[6];
				char day1=theDate[7];
				//int day=((int)day0-48)*10+((int)*day1-48);

				//修改日期格式
				theDate[4]='-';
				theDate[5]=month0;
				theDate[6]=month1;
				theDate[7]='-';
				theDate.append(&day0);
				theDate.append(&day1);
				cout<<"theDate="<<theDate<<endl;
			}
			else
			{
				cout<<"日期输入格式有误"<<endl;
				return;
			}
		}
		else if(theDate.length()==10)
		{
			if(DateFormat2(theDate))
			{
				

			} 
			else
			{
				cout<<"日期输入格式有误"<<endl;
				return;
			}
		}
		else if(theDate.length()>10)
		{
			cout<<"日期输入格式有误"<<endl;
			return;
		}
		ISBNNum=theISBNNum;
		name=theName;
		author=theAuthor;
		pblsDate=theDate;

		//初始化时默认未借出
		isOut=false;
	} 
};



 class Patron
 {
 private:
	 string name;
	 string	cardNum;
	 double oweCount;//欠费多少元
 public:
	 void DisplayInfo()
	 {
		 cout<<"读者信息------------------------------"<<endl;
		 cout<<"姓名:\t\t"<<name<<endl;
		 cout<<"图书卡号：\t"<<cardNum<<endl;
		 if(IsOwed())
			 cout<<"欠费信息：\t欠费"<<oweCount<<"元"<<endl;
		 else
			 cout<<"欠费信息：\t无欠费记录"<<endl;

		 cout<<endl;
	 }
	 string GetName()
	 {
		 return name;
	 }
	
	 string GetCardNum()
	 {
		 return cardNum;
	 }
	 double GetOweCount()
	 {
		 return oweCount;
	 }
	 void SetOweCount(double count)
	 {
		 if(count>0)
			oweCount=count;
		 else
			 cout<<"输入有误：借阅费必须是正的"<<endl<<"操作未完成"<<endl<<endl;
	 }
	 bool IsOwed()
	 {
		 if(oweCount>0)
			 return true;
		 else
			 return false;
	 }
	 Patron()
	 {
	 }

	 //构造函数
	 Patron(string theName,string theCardNum)
	 {
		 //输入正确性检查
		 name=theName;
		 cardNum=theCardNum;
	 }
 };

 //图书馆类
 class Library
 {
 private:
	  struct Transaction
	 {
	 public:
		 Book inBook;
		 Patron inPatron;
		 Date inDate;

		Transaction()
		{
		}
		void DisplayInfo()
		{
			cout<<"借阅信息------------------------------"<<endl;
			cout<<"图书信息----------------"<<endl;
			cout<<"书名：\t\t"<<inBook.GetName()<<endl;
			cout<<"作者：\t\t"<<inBook.GetAuthor()<<endl;
			cout<<"ISBN号：\t"<<inBook.GetISBNNum()<<endl;
			cout<<"出版日期：\t"<<inBook.GetDat()<<endl;

			cout<<"读者信息-----------------"<<endl;
			cout<<"姓名:\t\t"<<inPatron.GetName()<<endl;
			cout<<"图书卡号：\t"<<inPatron.GetCardNum()<<endl;
			cout<<"借书日期：\t"<<inDate.GetYear()<<"-"<<inDate.GetMonth()<<"-"<<inDate.GetDay()<<endl;
			if(inPatron.IsOwed())
				cout<<"欠费信息：\t欠费"<<inPatron.GetOweCount()<<"元"<<endl;
			else
				cout<<"欠费信息：\t无欠费记录"<<endl;

			cout<<endl;
		}
	 };
	
 public:
	 vector<Book>aBook;
	 vector<Patron>aPatron;
	 vector<Transaction>aTransaction;
	
	 //添加图书
	 void AddBook(Book newBook)
	 {
		 cout<<"新操作：\t录入图书信息"<<endl;
		 cout<<"准备就绪..."<<endl;

		 if(newBook.GetName()=="")
		 {
			  cout<<"图书信息输入有误"<<endl<<"操作未完成"<<endl<<endl;
			  return;
		 }
		 if(aBook.size()>0)
			 for(int i=0;i<aBook.size();i++)
				 if (aBook[i].GetName()==newBook.GetName())
				 {
					 cout<<"图书已经存在"<<endl<<"操作未完成"<<endl<<endl;
					 return ;
				 }
		
		//录入图书信息:
		
		cout<<"正在录入图书信息..."<<endl;
		aBook.push_back(newBook);
		cout<<"操作完成!"<<endl<<endl;
		newBook.DisplayInfo();
	 }

	 //添加读者
	 void AddPatron(Patron newPatron )
	 {
		 cout<<"新操作：\t录入读者信息"<<endl;
		 cout<<"准备就绪..."<<endl;

		 if(aPatron.size()>0)
			 for(int i=0;i<aPatron.size();i++)
				 if (aPatron[i].GetCardNum()==newPatron.GetCardNum())
				 {
					 cout<<"读者已经存在"<<endl<<"操作未完成"<<endl<<endl;
					 return ;
				 }
		
		cout<<"正在录入读者信息..."<<endl;
		aPatron.push_back(newPatron);
		cout<<"操作完成!"<<endl<<endl;
		newPatron.DisplayInfo();
		
	 }

	 //借出图书
	 void LendABookToPatron(Book existedBook,Patron existedPatron)
	 {
		 int bookOrder;
		 int patronOrder;

		 cout<<"新操作：\t借出图书"<<endl;
		 cout<<"准备就绪..."<<endl;

		 if(aBook.size()==0)
		 {
			cout<<"图书馆中没有书"<<endl<<"操作未完成"<<endl<<endl;
			return;
		 }
		 else if(aPatron.size()==0)
		 {
			  cout<<"学生信息系统为空"<<endl<<"操作未完成"<<endl<<endl;
			  return;
		 }
			
		 //检查书和读者是否存在 
		 bool bookExist=false;
		 for(int i=0;i<aBook.size();i++)
			if(existedBook.GetISBNNum()==aBook[i].GetISBNNum())//书存在 注意判断标准是ISBN因为书可能会重名
			{
				bookExist=true;
				bookOrder=i;

				//检查书是否已经借出
				if(aBook[bookOrder].GetIsOut())
				{
					cout<<"这本书已经被借出"<<endl<<"操作未完成"<<endl<<endl;
					break;
				}
				bool patronExist=false;
				for(int i=0;i<aPatron.size();i++)
					if(existedPatron.GetName()==aPatron[i].GetName())//读者信息存在
					{
						patronExist=true;
						patronOrder=i;
					
						//检查是否欠费
						if(aPatron[patronOrder].IsOwed())
						{
							cout<<"读者已欠费，请缴费后再借书"<<endl<<"操作未完成"<<endl<<endl;
							break;
						}
						else 
						{
							aBook[bookOrder].LendOut();
							Date aDate= Date();
							Transaction newTransaction;
							newTransaction.inBook=aBook[bookOrder];
							newTransaction.inPatron=aPatron[patronOrder];
							newTransaction.inDate=aDate;
							aTransaction.push_back(newTransaction);

							cout<<"正在录入借阅信息..."<<endl;
							cout<<"操作完成!"<<endl<<endl;
							newTransaction.DisplayInfo();
						}
					}
				if (!patronExist)
				{
					cout<<"系统中没有该用户，请先录入"<<endl<<"操作未完成"<<endl<<endl;
				}
			}
			if (!bookExist)
			{
				cout<<"系统中暂时没有这本书"<<endl<<"操作未完成"<<endl<<endl;			
			}
	 }
	
	 //显示欠费信息
	 void GetOwedInfo()
	 {
		cout<<"新操作：\t显示欠费名单"<<endl;
		cout<<"准备就绪..."<<endl;
		cout<<"正在进行操作..."<<endl;
		cout<<"操作完成，欠费信息如下"<<endl;
		cout<<"姓名\t图书证号\t欠费金额"<<endl;
		for(int i=0;i<aPatron.size();i++)
			if(aPatron[i].IsOwed())
				cout<<aPatron[i].GetName()<<"\t"<<aPatron[i].GetCardNum()<<"\t"<<aPatron[i].GetOweCount()<<"元"<<endl;
	 }
	 //归还图书
	 void ReturnBook(Book reBook,Patron rePatron)
	 {
		 bool bookExisted=false;
		 bool patronExisted=false;
		 bool transactionExisted=false;
		 int bookOrder=0;
		 int patronOrder=0;
		 int transactionOrder=0;

		 cout<<"新操作：\t归还图书"<<endl;
		 cout<<"准备就绪..."<<endl;
		 cout<<"正在进行操作..."<<endl;

		 //检查图书是否存在
		 for(int i=0;i<aBook.size();i++)
			 if(reBook.GetISBNNum()==aBook[i].GetISBNNum())
			 {
				 bookExisted=true;
				 bookOrder=i;
			 }
		 if(!bookExisted)
		 {
			 cout<<"无当前图书信息，请先录入"<<endl;
			 return;
		 }

		 //检查读者是否存在
		 for(int i=0;i<aPatron.size();i++)
			 if(rePatron.GetCardNum()==aPatron[i].GetCardNum())
			 {
				 patronExisted=true;
				 patronOrder=i;
			 }
		 if(!patronExisted)
		 {
			 cout<<"无当前读者信息，请先录入"<<endl;
			 return;
		 }

		 //判断该Transaction是否存在
		 for(int i=0;i<aTransaction.size();i++)
			 if(aTransaction[i].inBook.GetISBNNum()==reBook.GetISBNNum() && aTransaction[i].inPatron.GetCardNum()==rePatron.GetCardNum())
				{
					transactionExisted=true;
					transactionOrder=i;
				}
		if(!transactionExisted)
		{
				cout<<"借书记录中无此条记录，请仔细核对书名和读者姓名后再提交"<<endl;
				return;
		}

		 //修改图书的借出特性
		 aBook[bookOrder].ReturnIn();

		 //修改Transaction向量
		 //vector <Transaction>::iterator iter;
		 //iter=aTransaction.begin();
		 aTransaction.erase(aTransaction.begin()+transactionOrder);





		 
		 cout<<"操作完成，本次操作信息如下"<<endl;
		 cout<<"-----归还图书信息如下-----"<<endl;
		 cout<<"----还书者信息-----"<<endl;
		 cout<<"姓名：\t"<<rePatron.GetName()<<"读者证号：\t"<<rePatron.GetCardNum()<<endl;
		 cout<<"-----归还图书信息----"<<endl;
		 cout<<"书名:\t"<<reBook.GetName()<<"图书作者:\t"<<reBook.GetAuthor()<<endl;
		 
	 }
	 //显示借书列表
	 void DisplayOut()
	 {
		
		 cout<<endl;
		 cout<<"新操作：\t显示借出书列表"<<endl;
		 cout<<"准备就绪..."<<endl;
		 cout<<"正在进行操作..."<<endl;
		 cout<<"操作完成，本次操作信息如下"<<endl;
		 cout<<"----------借出图书列表----------\n";
		 if(aBook.size()==0)
			 cout<<"当前没有图书借出"<<endl;
		 else
		 {
			int orders=0;
			for (int i=0;i<aBook.size();i++)
				if (aBook[i].GetIsOut())
				{
					orders++;
					cout<<"序列号："<<orders<<"\t书名\t"<<aBook[i].GetName()<<endl;
				}
		 }
	 }
	 Library(){}
 };
 int main()
 {
	 string keep;
	 bool run=true;
	 int bookOrder=0;

	 Library ustcLibrary=Library();
	 while(run)
	 {
		 cout<<"-------------------主菜单---------------------\n";
		cout<<"0.退出\t1.添加\t2.查询\t3.借书\t4.还书\t5.费用\n";
		cout<<"请选择操作：\n";

		int  mainOperator=0;
		cin>>mainOperator;
	
		switch(mainOperator)
		{
		case 0:
			run=false;
			break;
		case 1:
			cout<<"------------添加子菜单------------\n";
			cout<<"0.返回\t1.添加图书\t2.添加读者\n";
			cout<<"请选择操作：\n";

			int addOperator=0;
			cin>>addOperator;

			switch(addOperator)
			{
			case 0:
				break;
			case 1:
				
				bookOrder=2;

				string strISBN;
				string strName;
				string strAuthor;
				string strPulishedDate;
				string getId;
				string getName;
				string getAuthor;
				string getPublishedDate;
				cout<<"----------添加图书----------\n";
				cout<<"请依次输入图书的ISBN码，书名，作者和出版日期：\n";
				cin>>strISBN>>strName>>strAuthor>>strPulishedDate;

				Book  newBook=Book(strISBN,strName,strAuthor,strPulishedDate);
				getId=newBook.GetISBNNum();
				bool wrongOnce=false;
				while(getId=="") 
				{
					wrongOnce=true;
					cout<<"请重新输入:\n";
					cin>>strISBN>>strName>>strAuthor>>strPulishedDate;
					Book newBook=Book(strISBN,strName,strAuthor,strPulishedDate);
					getId=newBook.GetISBNNum();
					getName=newBook.GetName();
					getAuthor=newBook.GetAuthor();
					getPublishedDate=newBook.GetDat();
				}
				if(wrongOnce)
				{
					Book rightBook=Book(getId,getName,getAuthor,getPublishedDate);
					ustcLibrary.AddBook(rightBook);
				}
				else
				{
					ustcLibrary.AddBook(newBook);
				}
				

			}

			break;
		}
	 }
	

	
	/*图书
	 //1.1初始化图书信息
	 Book newBook1= Book("1-2-2-s","面向对象技术1","林典鹏","2013-09-12");		//right
	 Book newBook2= Book("1-3-s-s","面向对象技术2","胡希望能","2013-09-12");		//wrong
	 Book newBook3=Book("1-2-3-w","C++ program","Jhon Tom","2012-10-19");
	 //1,2返回图书信息
	 cout<< newBook1.GetAuthor()<<endl;
	 cout<<newBook1.GetDat()<<endl;
	 cout<<newBook1.GetISBNNum()<<endl;
	 cout<<newBook1.GetIsOut()<<endl;
	 cout<<newBook1.GetName()<<endl;
	 newBook1.DisplayInfo();	//总体显示信息
// 


 ///*读者
	 //2.1初始化读者信息
	 Patron linPatron =Patron("林弘伟","PB11210245");
	 Patron wangPatron=Patron("王云峰","PB11210234");
	 Patron liPatron=Patron("李敏","SA11023234");
	 Patron xPatron=Patron("XJhon","PB12210345");
	 //2.2显示读者信息
	 linPatron.DisplayInfo();
	 wangPatron.DisplayInfo();
	 liPatron.DisplayInfo();
	 //2.3设定借书费
	 linPatron.SetOweCount(23.4);
	 //2.4显示是否欠费
	 linPatron.IsOwed();
	 linPatron.DisplayInfo();
// 

 ///*图书馆
	 //3.1新建图书馆
	 Library ustcLibrary=Library();
	 //3.2添加图书
	 ustcLibrary.AddBook(newBook1);					//right
	 ustcLibrary.AddBook(newBook2);					//wrong
	 ustcLibrary.AddBook(newBook3);
	 //3.3添加读者
	 ustcLibrary.AddPatron(linPatron);
	 ustcLibrary.AddPatron(wangPatron);
	 ustcLibrary.AddPatron(xPatron);
	 //3.4借书
	 ustcLibrary.LendABookToPatron(newBook1,wangPatron);		//欠费
	 ustcLibrary.LendABookToPatron(newBook1,wangPatron);	//未欠费
	 ustcLibrary.LendABookToPatron(newBook3,xPatron);
	// ustcLibrary.LendABookToPatron(newBook1,liPatron);		//已经借出
	 //3.5显示欠费读者列表
	 ustcLibrary.GetOwedInfo();
	 ustcLibrary.DisplayOut();
	 ustcLibrary.ReturnBook(newBook1,wangPatron);
	 ustcLibrary.DisplayOut();
//*/

	// cin>>keep;
 }

