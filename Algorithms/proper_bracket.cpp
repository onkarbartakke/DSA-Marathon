#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int i,j,l;
	    int a[3]={0};
	     int flag=1;
	    int count=0;
	    l=s.length();
	    if(l%2==1)
	    {
	        cout<<"NO\n";
	    }
	    else
	    {
	        for(i=0;i<l;i++)
	        {
	            if(s[i]=='(')
	            a[0]++;
	            else if(s[i]==')')
	            a[1]++;
	            else if(s[i]=='?')
	            a[2]++;
	        }
	        
	        if(a[0]==a[1] && a[2]%2==0)
	        {
	           
	            
	            for(i=0;i<l;i++)
	            {
	                if(s[i]=='(')
	                count++;
	                else if(s[i]==')')
	                count--;
	                
	                if(count<0)
	                {
	                    flag=0;
	                    break;
	                }
	            }
	            
	           if(count==0 && flag==1)
	           cout<<"YES\n";
	           else
	           cout<<"NO\n";
	        }
	        else
	        {
                if(a[2]<abs(a[0]-a[1]))
                cout<<"NO\n";
                else if(a[2]==abs(a[1]-a[0]))
                {
                    char c;
                    if(a[0]<a[1])
                    {
                        c='(';
                    }
                    else
                    {
                        c=')';
                    }
                    for(i=0;i<l;i++)
                    {
                        if(s[i]=='?')
                        s[i]=c;
                    }
                    
                    count=0;
                    flag=1;
                    for(i=0;i<l;i++)
                    {
                        if(s[i]=='(')
                        count++;
                        else if(s[i]==')')
                        count--;
                        
                        if(count<0)
                        {
                            flag=0;
                            break;
                        }
                    }
                    
                    if(count==0 && flag==1)
                    cout<<"YES\n";
                    else
                    cout<<"NO\n";
                }
                else
                {
                    if((a[2]-abs(a[1]-a[0]))%2==1)
                    cout<<"NO\n";
                    else
                    {
                        int countqu=0;
                        count=0;
                        flag=1;
                        for(i=0;i<l;i++)
                        {
                            if(s[i]=='(')
                            count++;
                            else if(s[i]=='?')
                            countqu++;
                            else if(s[i]==')')
                            count--;
                            
                            
                            if(count==-1 && countqu>=1)
                            {
                                count++;
                                countqu--;
                            }
                            else if(count==-1 && countqu==0)
                            {
                                flag=0;
                                break;
                            }
                        }
                        if(count==countqu)
                        {
                        	count=0;
                        	countqu=0;
						}
                        if(count==0 && countqu%2==0 && flag==1)
                        {
                            cout<<"YES\n";
                        }
                        else
                        cout<<"NO\n";
                    }
                }
                
	       
	        }
	    }
	    
	}
	return 0;
}
