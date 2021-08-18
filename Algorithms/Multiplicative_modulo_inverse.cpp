#include<iostream>

using namespace std;

/*
(A * B) % m =1

A and m are given find B

for multipicative modulo inverse to exist gcd(A,m)=1

(A*B)+ qm = 1
same to exteded Euclid
where x=B
      y=q
     GCD=1

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

int Multiplicative_modulo_inverse(int A, int m)
{
    triplet ans=Extended_Euclid(A,m);
    return ans.x;
}

int main()
{
    int A,m;
    int B=Multiplicative_modulo_inverse(A,m);

    cout<<"\nB -> "<<B;
}