#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m,i,j;

    cin>>n;
    vector<int>a(n);
    int sa=0,sb=0;
    int ea=0,eb=0,oa=0,ob=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];

        sa+=a[i];

        if(a[i]&1)
        oa++;
        else
        ea++;
    }

    cin>>m;

    vector<int>b(m);

    for(i=0;i<m;i++)
    {
        cin>>b[i];

        sb+=b[i];

        if(b[i]&1)
        ob++;
        else
        eb++;
    }

    if(sb%2==0 && sa%2==0)
    cout<<"0\n";
    else if(sb%2==1 && sa%2==1)
    {
        if(oa>0 && eb>0)
        cout<<"1\n";
        else if(ob>0 && ea>0)
        cout<<"1\n";
        else
        cout<<"-1\n";
    }
    else if(sa%2==0 && sb%2==1)
    {
        cout<<"-1\n";
    }
    else if(sa%2==1 && sb%2==0)
    {
        cout<<"-1\n";
    }


}