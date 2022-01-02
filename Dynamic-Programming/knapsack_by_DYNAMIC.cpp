#include <iostream>
using namespace std;

void knpsack_dynamic(int val[],int wt[],int n,int W)
{
    int **dp;
    int i,j;
    dp=new int*[n+1];
    for(i=0;i<n+1;i++)
    {
        dp[i]=new int[W+1];
    }
    
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
        {
            if(i==0 || j==0) //when num of obj=0 or num of wt=0 value will be 0
            dp[i][j]=0;
            else if(j<wt[i-1])   //if the max allowed weight j is less than the wt of ith object
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j], val[i-1]+dp[i-1][j-wt[i-1]]);  //consider max of both aftr including and excluding
            }
            
        }
    }
    
    cout<<"max value is "<<dp[n][W]<<"\n";
    cout<<"\n\n********\n\nDP table : \n\n";

    for(i=0;i<n+1;i++)
    {
        for(j=0;j<W+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    int *object;
    object=new int[n];
    for(i=0;i<n;i++)
    {
        object[i]=0;
    }
    i=n;
    j=W;
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            //cout<<i<<"-> "<<"0\n";
            object[i-1]=0;
            i--;
            
        }
        else
        {
            //cout<<i<<"-> "<<"1\n";
            object[i-1]=1;
            j=j-wt[i-1];
            i--;
            
        }
    }
    
    for(i=0;i<n;i++)
    {
        cout<<object[i]<<" "; //if 1,object is in bag else not
    }
}
int main() {
	int n,i;
	cout<<"enter the number of objects\n";
	cin>>n;
	cout<<"Enter weights and values of n items\n";
	int wt[n],val[n];
	for(i=0;i<n;i++)
	{
	    cin>>wt[i];
	}
	for(i=0;i<n;i++)
	{
	    cin>>val[i];
	}
	cout<<"Enter the max wt allowed in bag\n";
	int W;
	cin>>W;
	knpsack_dynamic(val,wt,n,W);
	return 0;
}