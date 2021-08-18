#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool mycomp(vector<int>&a , vector<int>&b)
{
    if(a[0]==b[0])
    return a[1]<b[1];
    else
    return a[0]>b[0];
}

int Russian_doll(vector<vector<int>>&E, int n)
{
    int i,j;
    vector<int>LIS(n,1);

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(E[i][1]<E[j][1] && LIS[i]<LIS[j]+1)
            {
                LIS[i]=LIS[j]+1;
            }
        }
    }

    int m=0;

    for(i=0;i<n;i++)
    {
        if(m<LIS[i])
        m=LIS[i];


        cout<<"( "<<E[i][0]<<" , "<<E[i][1]<<" )\n";
    }

    return m;
}

int main()
{
    int n,i;
    cout<<"Enter num of envelops : ";
    cin>>n;

    vector<vector<int>>E(n,vector<int>(2));
    cout<<"\nEnter the Width and Height : \n";
    for(i=0;i<n;i++)
    {
        cin>>E[i][0]>>E[i][1];
    }

    sort(E.begin(),E.end(),mycomp);

    cout<<"Number of Envelops that could be put nside eachother are :  "<<Russian_doll(E,n);

}