#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        int l = s.length();
        int a=0,b=0,c=0;

        for(int i=0;i<l;i++)
        {
            if(s[i]=='A')
            a++;
            else if(s[i]=='B')
            b++;
            else if(s[i]=='C')
            c++;
        }

        if(a+c == b)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}