#include<bits/stdc++.h>

using namespace std;

char nonrepeatingCharacter(string S)
{
   //Your code here
   int i,n;
   int hash[26]={0};
   int l=S.length();
   
   for(i=0;i<l;i++)
   {
       hash[S[i]-'a']++;
   }
   char c='$';
   for(i=0;i<l;i++)
   {
       if(hash[S[i]-'a']==1)
       {
           c=S[i];
           break;
       }
   }
   
   return c;
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    char c=nonrepeatingCharacter(s);
    cout<<"\n1st non repearing char is : "<<c;
}