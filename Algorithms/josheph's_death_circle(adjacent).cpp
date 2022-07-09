#include <iostream>
#include<math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


int main()
{
	int n;
	cout<<"Enter number of soliders\n";
	cin>>n;
	int count=0;
	int m=n;
	while(m!=0)
	{
		m=m/2;
		count++;
	} 
	count--;
	cout<<count<<"\n";
	cout<<pow(2,count)<<"\n";
	int l=n-pow(2,count);
	cout<<2*l+1;
}
