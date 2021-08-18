#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void permutate(char s[],int l,int h)
{
	int i;
	if(l==h)
	{
		cout<<s<<"\n";
	}
	else
	{
		for(i=l;i<=h;i++)
		{
			//swap(s[i],s[l]);
			char c;
			c=s[i];
			s[i]=s[l];
			s[l]=c;
			permutate(s,l+1,h);
			//swap(s[i],s[l]);
			c=s[i];
			s[i]=s[l];
			s[l]=c;
		}
	}
}
int main()
{
	char s[100];
	cout<<"Enter the string\n";
	cin>>s;
	permutate(s,0,strlen(s)-1);
}
