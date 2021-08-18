#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Next_sparse(int n)
{
    int i,m,j;
    vector<bool>bin ;
    m=n;
    while(m)
    {
        bin.push_back(m&1);
        m=m>>1;
    }
    bin.push_back(0);
    int l=bin.size();
    int last_final=0;
    /*for(i=l-1;i>=0;i--)
    {
        cout<<bin[i]<<" ";
    }*/
    
    cout<<"\n";
    for(i=1;i<l-1;i++)
    {
        if(bin[i]==1 && bin[i-1]==1 && bin[i+1]!=1)
        {
            bin[i+1]=1;
            for(j=i;j>=last_final;j--)
            {
                bin[j]=0;
            }
            last_final=i+1;
        }
    }
    
    
    /*for(i=l-1;i>=0;i--)
    {
        cout<<bin[i]<<" ";
    }*/
    cout<<"\n";
    int ans=0;
    
    for(i=l-1;i>=0;i--)
    {
    	ans=ans<<1;
        if(bin[i]&1)
        {
        	
        	ans=(ans|1);
		}
    }
    cout<<"\n";
    return ans;
}

int main() {
	int n;
	cin>>n;
	
	cout<<Next_sparse(n);
	return 0;
}
