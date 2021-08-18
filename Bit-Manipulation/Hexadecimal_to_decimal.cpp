#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int hexadecimal_to_decimal(string n)
{
    int s=n.length();
    int ans=0;
    int x=1;
    for(int i=s-1;i>=0;i--)
    {
        if(n[i]>='0' && n[i]<='9')
        {
            ans=ans+x*(n[i]-'0');
        }
        else if(n[i]>='A' && n[i]<='F')
        {
            ans=ans+x*(n[i]-'A'+10);
        }
        
        x=x*16;
    }
    
    return ans;
    
}
int main()
{
    string n;
    cin>>n;
    cout<<hexadecimal_to_decimal(n);
	return 0;
}
