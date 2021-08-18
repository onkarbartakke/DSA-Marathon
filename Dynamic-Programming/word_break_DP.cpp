#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int wordbreak(string A, vector<string>&B)
{
     int i,j,k;
    i=0;
    bool dp[A.size()+1];
    for(i=0;i<=A.size();i++)
    {
        dp[i]=false;
    }
    
    for(i=1;i<=A.size();i++)
    {
        if(dp[i]==false)
        {
            string s=A.substr(0,i);
            
            for(k=0;k<B.size();k++)
            {
                if(s.compare(B[k])==0)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        
        if(dp[i]==true)
        {
            if(i==A.size())
            return 1;
            
            for(j=i+1;j<=A.size();j++)
            {
                if(dp[j]==false)
                {
                    string s=A.substr(i,j-i);
                    for(k=0;k<B.size();k++)
                    {
                        if(s.compare(B[k])==0)
                        {
                            dp[j]=true;
                            break;
                        }
                    }
                }
                
                if(j==A.size() && dp[j]==true)
                return 1;
            }
        }
        
    }
    
    return 0;
}

int main() {
	int n,i;
	cin>>n;
	vector<string>dict;
	string s;
	for(i=0;i<n;i++)
	{
	    cin>>s;
	    dict.push_back(s);
	}
	string A;
	cin>>A;
	
	cout<<wordbreak(A,dict);
	return 0;
}