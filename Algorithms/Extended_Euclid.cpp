+#include<iostream>

using namespace std;
/*
ax + by = gcd(a,b)
gcd(a,b)=gcd(b,a%b)

a%b= a - (a/b)*b

bx1 + (a%b)y1 = ax + by

bx1 + (a-(a/b)*b)y1= ax + by

ax + by = ay1 + b(x1 - (a/b)*y1)

hence,

x=y1

y= ( x1 - (a/b)*y1 )


*/
struct triplet
{
    int x;
    int y;
    int gcd;
};

triplet Extended_Euclid(int a,int b)
{
    triplet ans;

    if(b==0)
    {
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }

    triplet smallAns=Extended_Euclid(b,a%b);

    ans.x=smallAns.y;
    ans.y=smallAns.x- (a/b)*smallAns.y;
    ans.gcd=smallAns.gcd;

    return ans;
}

int main()
{
    int a,b;
    cin>>a>>b;

    triplet ans=Extended_Euclid(a,b);

    cout<<"x-> "<<ans.x<<" y-> "<<ans.y<<" GCD-> "<<ans.gcd;
}