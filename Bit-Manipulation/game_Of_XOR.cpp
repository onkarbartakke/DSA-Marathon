#include <iostream>
using namespace std;

int game0fX0R(int N,int A[])
{
        if(N%2==0)
        {
           int sum=0;
           return sum;
        }
        else
        {
            int i;
            int sum=0;
            for(i=0;i<N;i=i+2)
            {
                sum=sum^A[i];
            }
            return sum;
        }
        
}        
int main() {
	int i,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	cout<<game0fX0R(n,a);
	return 0;
}