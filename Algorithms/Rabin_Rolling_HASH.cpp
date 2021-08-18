#include<iostream>
#include<string>
#include<math.h>
#define d 26
using namespace std;


bool check( unsigned long long int i,  unsigned long long int j, string s, string p)
{
    unsigned long long int k=i;
     unsigned long long int t=0;
    while(k<=j)
    {
        if(s[k]==p[t])
        {
            t++;
            k++;
        }
        else
        {
            return false;
        }
    }

    return true;
}

void search_by_RollingHash(string s, string p)
{
    unsigned long long int l1,l2,i,j,key,k,point;
    l1=s.length();
    l2=p.length();
    k=0;
    point=0;
    key=0;
    for(i=l2-1;i>=0;i--)
    {
        key=key+ p[i]*(pow(d,k));
        point=point + s[i]*(pow(d,k));
        //key=key%limit;
        //point=point%limit;
        k++;
    }
    int f=0;
    for(i=0,j=l2-1;j<l1;i++,j++)
    {
        if(point==key && check(i,j,s,p))
        {
            cout<<"Pattern Found from i to j "<<i<<" - "<<j;
            cout<<"\n\n";
            for(;i<=j;i++)
            cout<<s[i];
            f=1;
            break;
        }
        else
        {
            point=point-(s[i]*pow(d,l2-1));
            point=point*d;
            //point=point%limit;
            if(j+1<l1)
            point=point+s[j+1];
        }
    }

    if(f==0)
    cout<<"Pattern not Found\n";

}

int main()
{
    string s,p;
    cout<<"Enter the main String : ";
    cin>>s;
    cout<<"\n\nEnter the patterend to be searched : ";
    cin>>p;

    search_by_RollingHash(s,p);

}