#include<bits/stdc++.h>

using namespace std;

void  print_brackets(int i, int j, int **bracket, char& name)
{
    if(i==j)
    {
        cout<<name;
        name++;
        return;
    }
    cout<<"(";
    print_brackets(i,bracket[i][j],bracket,name);
    print_brackets(bracket[i][j]+1,j,bracket,name);
    cout<<")";
}

int Min_num_muls(int d[], int n)
{                                           //Example Test case- //40, 20, 30, 10, 30 
    int c[n][n];
    int i,j,k,q;
    for(i=0;i<n;i++)
    {
        c[i][i]=0;
    }
    int **bracket;
    bracket=new int*[n];
    for(i=0;i<n;i++)
    {
        bracket[i]=new int[n];
    }
    int len;
    for(len=2;len<=n-1;len++)
    {
        for(i=1;i<n-len+1;i++)
        {
            j=i+len-1;
            c[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                q=c[i][k]+c[k+1][j]+(d[i-1]*d[k]*d[j]);
                if(q<c[i][j])
                {
                    c[i][j]=q;
                    bracket[i][j]=k;
                }
            }
        }
    }
    char name='A';
    print_brackets(1,n-1,bracket,name);
    return c[1][n-1];
}

int main()
{
    int n,i;
    cout<<"Enter the number(n) of matrices to multiply : ";
    cin>>n;
    n=n+1;
    //since dimensions will be 1 more
    // e.g if dimensions in order are 40 20 30 10 (4) then matrices are (3) in order
    //They are - 40 x 20 , 20 x 30 , 30 x 10
    cout<<"\nEnter the dimensions (n+1): \n ";
    int dimensions[n];
    for(i=0;i<n;i++)
    {
        cin>>dimensions[i];
    }
    cout<<"\n";
    int ans=Min_num_muls(dimensions,n);
    cout<<"\n\nMinimum number of muls are : "<<ans;
}