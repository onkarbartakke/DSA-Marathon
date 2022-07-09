#include <bits/stdc++.h>

using namespace std;

bool lucky_num(int n)
{
    static int counter=2;
    if(counter>n)
    return true;
    else if(counter%2==0)
    return false;

    int np=n;
    np=np-np/counter;
    counter++;

    return lucky_num(np);
}

int main()
{
    int n;
    cout<<"Enter the num : ";
    cin>>n;
    cout<<"\n";
    if(lucky_num(n))
    {
        cout<<"its lucky number\n";
    }
    else
    {
        cout<<"its not lucky num\n";
    }
}
