//���⣺1 Date����
#include <iostream>
#include <time.h>
#include "std_lib_facilities.h"
#define MaxSizeOfNameSpace 1000

//������
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
		time_t now=time(0);//ע��һ��Ҫ��ʼ��
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
	//��ʾǷ��ѧ������
	void DisplayInfo()
	{
		cout<<"������\t"<<name<<endl;
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

	//��ʾ��Ϣ
	void DisplayInfo()
	{
		cout<<"ͼ����Ϣ------------------------------"<<endl;
		cout<<"ISBN�ţ�\t"<<ISBNNum<<endl;
		cout<<"������\t\t"<<name<<endl;
		cout<<"���ߣ�\t\t"<<author<<endl;
		cout<<"�������ڣ�\t"<<pblsDate<<endl;
		cout<<"�Ƿ�����\t";
		if(isOut)
			cout<<"�ѽ��"<<endl;
		else
			cout<<"δ���"<<endl;
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
		//1.���ȫ������
		for(int i=0;i<8;i++)
			if(date[i]>'9' ||date[i]<'0')
				allIsNum=false;
		if(!allIsNum)
		{
			cout<<"���ڸ�ʽ�д���"<<endl;
			return false;
		}

		//2.������ڸ�ʽ
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
		//ISNB��ʽ���
		if(theISBNNum.length()<6)
		{
			cout<<"ISBN�������ʽ����"<<endl;
			return;
		}
		if((int)theISBNNum[0]<'0' || (int)theISBNNum[0]>'9'
			|| (int)theISBNNum[2]<'0' || (int)theISBNNum[2]>'9'
			||(int)theISBNNum[4]<'0' || (int)theISBNNum[4]>'9'
			||(((int)theISBNNum[6]<'0' || (int)theISBNNum[6]>'9')
				&&((char)theISBNNum[6]>'z'||(char)theISBNNum[6]<'a')
				&&((char)theISBNNum[6]>'Z'||(char)theISBNNum[6]<'A')))
		{
			cout<<"ISBN�������ʽ����"<<endl;
			return;
		}
		
		//���ڼ��
		if(theDate.length()<8)
		{
			cout<<"���������ʽ����"<<endl;
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

				//�޸����ڸ�ʽ
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
				cout<<"���������ʽ����"<<endl;
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
				cout<<"���������ʽ����"<<endl;
				return;
			}
		}
		else if(theDate.length()>10)
		{
			cout<<"���������ʽ����"<<endl;
			return;
		}
		ISBNNum=theISBNNum;
		name=theName;
		author=theAuthor;
		pblsDate=theDate;

		//��ʼ��ʱĬ��δ���
		isOut=false;
	} 
};



 class Patron
 {
 private:
	 string name;
	 string	cardNum;
	 double oweCount;//Ƿ�Ѷ���Ԫ
 public:
	 void DisplayInfo()
	 {
		 cout<<"������Ϣ------------------------------"<<endl;
		 cout<<"����:\t\t"<<name<<endl;
		 cout<<"ͼ�鿨�ţ�\t"<<cardNum<<endl;
		 if(IsOwed())
			 cout<<"Ƿ����Ϣ��\tǷ��"<<oweCount<<"Ԫ"<<endl;
		 else
			 cout<<"Ƿ����Ϣ��\t��Ƿ�Ѽ�¼"<<endl;

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
			 cout<<"�������󣺽��ķѱ���������"<<endl<<"����δ���"<<endl<<endl;
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

	 //���캯��
	 Patron(string theName,string theCardNum)
	 {
		 //������ȷ�Լ��
		 name=theName;
		 cardNum=theCardNum;
	 }
 };

 //ͼ�����
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
			cout<<"������Ϣ------------------------------"<<endl;
			cout<<"ͼ����Ϣ----------------"<<endl;
			cout<<"������\t\t"<<inBook.GetName()<<endl;
			cout<<"���ߣ�\t\t"<<inBook.GetAuthor()<<endl;
			cout<<"ISBN�ţ�\t"<<inBook.GetISBNNum()<<endl;
			cout<<"�������ڣ�\t"<<inBook.GetDat()<<endl;

			cout<<"������Ϣ-----------------"<<endl;
			cout<<"����:\t\t"<<inPatron.GetName()<<endl;
			cout<<"ͼ�鿨�ţ�\t"<<inPatron.GetCardNum()<<endl;
			cout<<"�������ڣ�\t"<<inDate.GetYear()<<"-"<<inDate.GetMonth()<<"-"<<inDate.GetDay()<<endl;
			if(inPatron.IsOwed())
				cout<<"Ƿ����Ϣ��\tǷ��"<<inPatron.GetOweCount()<<"Ԫ"<<endl;
			else
				cout<<"Ƿ����Ϣ��\t��Ƿ�Ѽ�¼"<<endl;

			cout<<endl;
		}
	 };
	
 public:
	 vector<Book>aBook;
	 vector<Patron>aPatron;
	 vector<Transaction>aTransaction;
	
	 //���ͼ��
	 void AddBook(Book newBook)
	 {
		 cout<<"�²�����\t¼��ͼ����Ϣ"<<endl;
		 cout<<"׼������..."<<endl;

		 if(newBook.GetName()=="")
		 {
			  cout<<"ͼ����Ϣ��������"<<endl<<"����δ���"<<endl<<endl;
			  return;
		 }
		 if(aBook.size()>0)
			 for(int i=0;i<aBook.size();i++)
				 if (aBook[i].GetName()==newBook.GetName())
				 {
					 cout<<"ͼ���Ѿ�����"<<endl<<"����δ���"<<endl<<endl;
					 return ;
				 }
		
		//¼��ͼ����Ϣ:
		
		cout<<"����¼��ͼ����Ϣ..."<<endl;
		aBook.push_back(newBook);
		cout<<"�������!"<<endl<<endl;
		newBook.DisplayInfo();
	 }

	 //��Ӷ���
	 void AddPatron(Patron newPatron )
	 {
		 cout<<"�²�����\t¼�������Ϣ"<<endl;
		 cout<<"׼������..."<<endl;

		 if(aPatron.size()>0)
			 for(int i=0;i<aPatron.size();i++)
				 if (aPatron[i].GetCardNum()==newPatron.GetCardNum())
				 {
					 cout<<"�����Ѿ�����"<<endl<<"����δ���"<<endl<<endl;
					 return ;
				 }
		
		cout<<"����¼�������Ϣ..."<<endl;
		aPatron.push_back(newPatron);
		cout<<"�������!"<<endl<<endl;
		newPatron.DisplayInfo();
		
	 }

	 //���ͼ��
	 void LendABookToPatron(Book existedBook,Patron existedPatron)
	 {
		 int bookOrder;
		 int patronOrder;

		 cout<<"�²�����\t���ͼ��"<<endl;
		 cout<<"׼������..."<<endl;

		 if(aBook.size()==0)
		 {
			cout<<"ͼ�����û����"<<endl<<"����δ���"<<endl<<endl;
			return;
		 }
		 else if(aPatron.size()==0)
		 {
			  cout<<"ѧ����ϢϵͳΪ��"<<endl<<"����δ���"<<endl<<endl;
			  return;
		 }
			
		 //�����Ͷ����Ƿ���� 
		 bool bookExist=false;
		 for(int i=0;i<aBook.size();i++)
			if(existedBook.GetISBNNum()==aBook[i].GetISBNNum())//����� ע���жϱ�׼��ISBN��Ϊ����ܻ�����
			{
				bookExist=true;
				bookOrder=i;

				//������Ƿ��Ѿ����
				if(aBook[bookOrder].GetIsOut())
				{
					cout<<"�Ȿ���Ѿ������"<<endl<<"����δ���"<<endl<<endl;
					break;
				}
				bool patronExist=false;
				for(int i=0;i<aPatron.size();i++)
					if(existedPatron.GetName()==aPatron[i].GetName())//������Ϣ����
					{
						patronExist=true;
						patronOrder=i;
					
						//����Ƿ�Ƿ��
						if(aPatron[patronOrder].IsOwed())
						{
							cout<<"������Ƿ�ѣ���ɷѺ��ٽ���"<<endl<<"����δ���"<<endl<<endl;
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

							cout<<"����¼�������Ϣ..."<<endl;
							cout<<"�������!"<<endl<<endl;
							newTransaction.DisplayInfo();
						}
					}
				if (!patronExist)
				{
					cout<<"ϵͳ��û�и��û�������¼��"<<endl<<"����δ���"<<endl<<endl;
				}
			}
			if (!bookExist)
			{
				cout<<"ϵͳ����ʱû���Ȿ��"<<endl<<"����δ���"<<endl<<endl;			
			}
	 }
	
	 //��ʾǷ����Ϣ
	 void GetOwedInfo()
	 {
		cout<<"�²�����\t��ʾǷ������"<<endl;
		cout<<"׼������..."<<endl;
		cout<<"���ڽ��в���..."<<endl;
		cout<<"������ɣ�Ƿ����Ϣ����"<<endl;
		cout<<"����\tͼ��֤��\tǷ�ѽ��"<<endl;
		for(int i=0;i<aPatron.size();i++)
			if(aPatron[i].IsOwed())
				cout<<aPatron[i].GetName()<<"\t"<<aPatron[i].GetCardNum()<<"\t"<<aPatron[i].GetOweCount()<<"Ԫ"<<endl;
	 }
	 //�黹ͼ��
	 void ReturnBook(Book reBook,Patron rePatron)
	 {
		 bool bookExisted=false;
		 bool patronExisted=false;
		 bool transactionExisted=false;
		 int bookOrder=0;
		 int patronOrder=0;
		 int transactionOrder=0;

		 cout<<"�²�����\t�黹ͼ��"<<endl;
		 cout<<"׼������..."<<endl;
		 cout<<"���ڽ��в���..."<<endl;

		 //���ͼ���Ƿ����
		 for(int i=0;i<aBook.size();i++)
			 if(reBook.GetISBNNum()==aBook[i].GetISBNNum())
			 {
				 bookExisted=true;
				 bookOrder=i;
			 }
		 if(!bookExisted)
		 {
			 cout<<"�޵�ǰͼ����Ϣ������¼��"<<endl;
			 return;
		 }

		 //�������Ƿ����
		 for(int i=0;i<aPatron.size();i++)
			 if(rePatron.GetCardNum()==aPatron[i].GetCardNum())
			 {
				 patronExisted=true;
				 patronOrder=i;
			 }
		 if(!patronExisted)
		 {
			 cout<<"�޵�ǰ������Ϣ������¼��"<<endl;
			 return;
		 }

		 //�жϸ�Transaction�Ƿ����
		 for(int i=0;i<aTransaction.size();i++)
			 if(aTransaction[i].inBook.GetISBNNum()==reBook.GetISBNNum() && aTransaction[i].inPatron.GetCardNum()==rePatron.GetCardNum())
				{
					transactionExisted=true;
					transactionOrder=i;
				}
		if(!transactionExisted)
		{
				cout<<"�����¼���޴�����¼������ϸ�˶������Ͷ������������ύ"<<endl;
				return;
		}

		 //�޸�ͼ��Ľ������
		 aBook[bookOrder].ReturnIn();

		 //�޸�Transaction����
		 //vector <Transaction>::iterator iter;
		 //iter=aTransaction.begin();
		 aTransaction.erase(aTransaction.begin()+transactionOrder);





		 
		 cout<<"������ɣ����β�����Ϣ����"<<endl;
		 cout<<"-----�黹ͼ����Ϣ����-----"<<endl;
		 cout<<"----��������Ϣ-----"<<endl;
		 cout<<"������\t"<<rePatron.GetName()<<"����֤�ţ�\t"<<rePatron.GetCardNum()<<endl;
		 cout<<"-----�黹ͼ����Ϣ----"<<endl;
		 cout<<"����:\t"<<reBook.GetName()<<"ͼ������:\t"<<reBook.GetAuthor()<<endl;
		 
	 }
	 //��ʾ�����б�
	 void DisplayOut()
	 {
		
		 cout<<endl;
		 cout<<"�²�����\t��ʾ������б�"<<endl;
		 cout<<"׼������..."<<endl;
		 cout<<"���ڽ��в���..."<<endl;
		 cout<<"������ɣ����β�����Ϣ����"<<endl;
		 cout<<"----------���ͼ���б�----------\n";
		 if(aBook.size()==0)
			 cout<<"��ǰû��ͼ����"<<endl;
		 else
		 {
			int orders=0;
			for (int i=0;i<aBook.size();i++)
				if (aBook[i].GetIsOut())
				{
					orders++;
					cout<<"���кţ�"<<orders<<"\t����\t"<<aBook[i].GetName()<<endl;
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
		 cout<<"-------------------���˵�---------------------\n";
		cout<<"0.�˳�\t1.���\t2.��ѯ\t3.����\t4.����\t5.����\n";
		cout<<"��ѡ�������\n";

		int  mainOperator=0;
		cin>>mainOperator;
	
		switch(mainOperator)
		{
		case 0:
			run=false;
			break;
		case 1:
			cout<<"------------����Ӳ˵�------------\n";
			cout<<"0.����\t1.���ͼ��\t2.��Ӷ���\n";
			cout<<"��ѡ�������\n";

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
				cout<<"----------���ͼ��----------\n";
				cout<<"����������ͼ���ISBN�룬���������ߺͳ������ڣ�\n";
				cin>>strISBN>>strName>>strAuthor>>strPulishedDate;

				Book  newBook=Book(strISBN,strName,strAuthor,strPulishedDate);
				getId=newBook.GetISBNNum();
				bool wrongOnce=false;
				while(getId=="") 
				{
					wrongOnce=true;
					cout<<"����������:\n";
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
	

	
	/*ͼ��
	 //1.1��ʼ��ͼ����Ϣ
	 Book newBook1= Book("1-2-2-s","���������1","�ֵ���","2013-09-12");		//right
	 Book newBook2= Book("1-3-s-s","���������2","��ϣ����","2013-09-12");		//wrong
	 Book newBook3=Book("1-2-3-w","C++ program","Jhon Tom","2012-10-19");
	 //1,2����ͼ����Ϣ
	 cout<< newBook1.GetAuthor()<<endl;
	 cout<<newBook1.GetDat()<<endl;
	 cout<<newBook1.GetISBNNum()<<endl;
	 cout<<newBook1.GetIsOut()<<endl;
	 cout<<newBook1.GetName()<<endl;
	 newBook1.DisplayInfo();	//������ʾ��Ϣ
// 


 ///*����
	 //2.1��ʼ��������Ϣ
	 Patron linPatron =Patron("�ֺ�ΰ","PB11210245");
	 Patron wangPatron=Patron("���Ʒ�","PB11210234");
	 Patron liPatron=Patron("����","SA11023234");
	 Patron xPatron=Patron("XJhon","PB12210345");
	 //2.2��ʾ������Ϣ
	 linPatron.DisplayInfo();
	 wangPatron.DisplayInfo();
	 liPatron.DisplayInfo();
	 //2.3�趨�����
	 linPatron.SetOweCount(23.4);
	 //2.4��ʾ�Ƿ�Ƿ��
	 linPatron.IsOwed();
	 linPatron.DisplayInfo();
// 

 ///*ͼ���
	 //3.1�½�ͼ���
	 Library ustcLibrary=Library();
	 //3.2���ͼ��
	 ustcLibrary.AddBook(newBook1);					//right
	 ustcLibrary.AddBook(newBook2);					//wrong
	 ustcLibrary.AddBook(newBook3);
	 //3.3��Ӷ���
	 ustcLibrary.AddPatron(linPatron);
	 ustcLibrary.AddPatron(wangPatron);
	 ustcLibrary.AddPatron(xPatron);
	 //3.4����
	 ustcLibrary.LendABookToPatron(newBook1,wangPatron);		//Ƿ��
	 ustcLibrary.LendABookToPatron(newBook1,wangPatron);	//δǷ��
	 ustcLibrary.LendABookToPatron(newBook3,xPatron);
	// ustcLibrary.LendABookToPatron(newBook1,liPatron);		//�Ѿ����
	 //3.5��ʾǷ�Ѷ����б�
	 ustcLibrary.GetOwedInfo();
	 ustcLibrary.DisplayOut();
	 ustcLibrary.ReturnBook(newBook1,wangPatron);
	 ustcLibrary.DisplayOut();
//*/

	// cin>>keep;
 }

