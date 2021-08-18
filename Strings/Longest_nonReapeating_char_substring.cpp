#include<iostream>

using namespace std;

string Non_repeating(string s)
{
    int i,j,l;
    l=s.length();
    int len,wid;
    int hash[26];
    for(i=0;i<26;i++)
    {
        hash[i]=-1;
    }

    i=0;
    j=0;
    len=0;
    int x,y;
    while(j<l)
    {

        if(hash[s[j]-'a']==-1)
        {
            wid=j-i+1;
            hash[s[j]-'a']=j;
            //cout<<wid<<"\n";
        }
        else
        {
            for(;i<=hash[s[j]-'a'];i++)
            {
                hash[s[i]-'a']=-1;
            }
            hash[s[j]-'a']=j;
            wid=j-i+1;
        }
        if(wid>len)
        {
            len=wid;
            x=i;
            y=j;
        }
        j++;
    }

    cout<<"\n"<<len<<"\n";
    char ans[len+1];
    ans[len]='\0';
    int k=0;
    for(i=x;i<=y;i++)
    {
        ans[k]=s[i];
        k++;
    }
    return ans;
}

int main()
{
    cout<<"Enter the string : ";
    string s;
    cin>>s;
    string ans=Non_repeating(s);
    cout<<"Longest Non-repeating substring is "<<ans;
}