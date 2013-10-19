//问题：1 Date函数

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

	Book(string theISBNNum,string theName,string theAuthor,string theDate)
	{
		//输入检查
		if((int)theISBNNum[0]<48 || (int)theISBNNum[0]>57
			|| (int)theISBNNum[1]<48 || (int)theISBNNum[1]>57 
			||(int)theISBNNum[2]<48 || (int)theISBNNum[2]>57 
			||(((int)theISBNNum[3]<48 || (int)theISBNNum[3]>57)
				&&((char)theISBNNum[3]>'z'||(char)theISBNNum[3]<'a')
				&&((char)theISBNNum[3]>'Z'||(char)theISBNNum[3]<'A')))
		{
			cout<<"ISBN码输入有误"<<endl;
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
	 double oweCount;
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
			if(existedBook.GetISBNNum()==aBook[i].GetISBNNum())//书存在 注意判断标准时ISBN因为书可能会重名
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
	 Library(){}
 };
 int main()
 {
	 string keep;

	///*图书
	 //1.1初始化图书信息
	 Book newBook1= Book("122s","面向对象技术","林典鹏","2013-09-12");		//right
	 Book newBook2= Book("132s","面向对象技术","林典鹏","2013-09-12");		//wrong
	 //1,2返回图书信息
	 cout<< newBook1.GetAuthor()<<endl;
	 cout<<newBook1.GetDat()<<endl;
	 cout<<newBook1.GetISBNNum()<<endl;
	 cout<<newBook1.GetIsOut()<<endl;
	 cout<<newBook1.GetName()<<endl;
	 newBook1.DisplayInfo();	//总体显示信息
 //*/


 ///*读者
	 //2.1初始化读者信息
	 Patron linPatron =Patron("林弘伟","PB11210245");
	 Patron wangPatron=Patron("王云峰","PB11210234");
	 Patron liPatron=Patron("李敏","SA11023234");
	 //2.2显示读者信息
	 linPatron.DisplayInfo();
	 wangPatron.DisplayInfo();
	 liPatron.DisplayInfo();
	 //2.3设定借书费
	 linPatron.SetOweCount(23.4);
	 //2.4显示是否欠费
	 linPatron.IsOwed();
	 linPatron.DisplayInfo();
// */

//  /*图书馆
	 //3.1新建图书馆
	 Library ustcLibrary=Library();
	 //3.2添加图书
	 ustcLibrary.AddBook(newBook1);					//right
	 ustcLibrary.AddBook(newBook2);					//wrong
	 //3.3添加读者
	 ustcLibrary.AddPatron(linPatron);
	 ustcLibrary.AddPatron(wangPatron);
	 //3.4借书
	 ustcLibrary.LendABookToPatron(newBook1,wangPatron);		//欠费
	 ustcLibrary.LendABookToPatron(newBook1,wangPatron);	//未欠费
	// ustcLibrary.LendABookToPatron(newBook1,liPatron);		//已经借出
	 //3.5显示欠费读者列表
	 ustcLibrary.GetOwedInfo();
// */

	 cin>>keep;
 }

