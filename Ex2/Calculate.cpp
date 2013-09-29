#include <iostream>
#include "std_lib_facilities.h"
#define Below_zero		0
#define Bad_operator	1
#define Bad_num			2
using namespace std;


//将字符串转化为数值类型
double StrToNum(string s)
{
	double num;
	stringstream ss(s);
	ss>>num;
	return num;
}

//将数值类型转化为字符串类型
string NumToStr(double i)
{
	string s;
	stringstream ss;
	ss<<i;
	return ss.str();
}

bool IsNotInt(string input)
{
	int order;
	order=input.find_first_of('.');
	if(order>=0)
		return true;
	else
		return false;
}
//检查是否小于零 
void IsBelowZero(string data1,string data2)
{
	if (data1[0]=='-' || data2[0]=='-')
			throw Below_zero;
}

//检查运算符
void IsRightOperator(string operators)
{
	if ((operators=="+") || (operators=="-") ||(operators=="*") ||(operators=="/") ||(operators=="%" ))
	{
	}
	else
	{
		throw Bad_operator;
	}
}

//检查除数是否为零
void IsDividedByZero(string operators,string data2)
{
	if(operators=="/" || operators=="%")
		if(data2[0]=='0')
			throw Bad_num;
}
int main()
{
	bool isInputError=false;
	double element1=0;
	double element2=0;
	double result=0;
	char theOperator=' ';
	string outputOperator="";

	string strElement1="";
	string strElement2="";
	string strTheOperator="";
	string keep;


	cout<<"请依次输入第一个操作数、第二个操作数、运算符,用空格分隔："<<endl;
	do
	{
		cin>>strElement1>>strElement2>>strTheOperator;

		//错误检查
		try
		{
			
			IsBelowZero(strElement1,strElement2);

			IsRightOperator(strTheOperator); 
			IsDividedByZero(strTheOperator,strElement2);
		}
		catch(int  errorNum)
		{
			if (errorNum==Below_zero)
			{
				cout<<"Below_Zero_Error：输入参数小于零"<<endl;
			}
			else  if(errorNum==Bad_operator)
			{
				cout<<"Bad_Operator_Error:输入运算符错误"<<endl;
			}
			else if(errorNum==Bad_num)
			{
				 cout<<"Bad_Num_Error:除数或被求模数不能为0"<<endl;
			}

			cin>>keep;
		}

		if (strTheOperator=="%" && (IsNotInt(strElement1) || IsNotInt(strElement2)))
		{
			isInputError=true;
			cout<<"ERROR：模运算操作数必须是整数.请重新输入："<<endl;
		}
		else
			isInputError=false;
	}while (isInputError);

	//将字符型赋值给数值型
	element1=StrToNum(strElement1);
	element2=StrToNum(strElement2);
	theOperator=strTheOperator[0];
	
	switch (theOperator)
	{
		case '+':
			result=element1+element2;
			outputOperator="和";
			break;
		case '-':
			result=element1-element2;
			outputOperator="差";
			break;
		case '*':
			result=element1*element2;
			outputOperator="积";
			break;
		case '/':
			result=element1/element2;
			outputOperator="商";
			break;
		case '%':
			result=((int)element1)%((int)element2);
			outputOperator="求模";
			break;
	default:
			break;
	}

	//输出运算结果
	cout<<element1<<"与"<<element2<<"的"<<outputOperator<<"等于"<<result;

	cin>>keep;
	return  0;

}