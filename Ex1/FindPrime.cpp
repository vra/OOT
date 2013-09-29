#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

bool IsPrime(int number)
{
	for(int i=2;i<=number/2;i++)
		if(number%i==0)
			return false;

	return true;
}
int main()
{
	vector<int>temps;
	temps.push_back(2);
	int count=1;
	int input;

	for(int i=3;i<=100;i++)
	{
		if(IsPrime(i))
		{
			temps.push_back(i);
			count++;
		}
	}
	cout<<"There are "<<count<<" primes between 0 and 100,they are：\n";
	for(int i=0;i<count;i++)
	{
		cout<<temps[i]<<"\t";
		if ((i+1)%8==0)
			cout<<endl;
	}
		
	cin>>input;
	return 0;
}
