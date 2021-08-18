#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void printchange(int n)
{
	int i;
	if(n<3 || n==4 || n==7)
	{
		cout<<"-1\n";
	}
	else if(n%5==0)
	{
		if(n%10==0)
		{
			for(i=1;i<n/10;i++)
			{
				cout<<"10+";
			}
			cout<<"10";
		}
		else
		{
			cout<<"5";
			
			for(i=0;i<n-5/10;i++)
			{
				cout<<"+10";
			}
			
		}
	}
	else
	{
		cout<<"3+";
		printchange(n-3);
	}
}
int main() {
	
	int n;
	cin>>n;
	int count=0;
	printchange(n);
	return 0;
}
