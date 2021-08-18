#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> Multiply(vector<vector<int>>&a, vector<vector<int>>&b)
{
    int i,j,k,n;
    n=a.size();

    vector<vector<int>>ans(n,vector<int>(n,0));

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                ans[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }

    return ans;
}

vector<vector<int>> Matrix_Exponentiation(vector<vector<int>>&a, int n)
{
    int sz,i,j;
    sz=a.size();

    if(n==0)
    {   
        vector<vector<int>>identity(sz,vector<int>(sz,0));

        for(i=0;i<sz;i++)
        identity[i][i]=1;

        return identity;
    }

    if(n==1)
    {
        return a;
    }

    vector<vector<int>>temp=Matrix_Exponentiation(a,n/2);
    vector<vector<int>>ans=Multiply(temp,temp);
    if(n&1)
    {
        ans=Multiply(ans,a);
    }

    return ans;
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>>a(2,vector<int>(2,0));
    a[0][0]=a[0][1]=a[1][0]=1;
    a[1][1]=0;
    /*
    1 1
    1 0
    */

    vector<vector<int>>ans=Matrix_Exponentiation(a,n);


    cout<<"\n\n";
    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }


    cout<<"\nFib("<<n<<") = "<<ans[0][1];
}

//Fib in Log(N) time