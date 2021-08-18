#include <iostream>
using namespace std;

int main() {
	int num,i,result;
	cin>>num;
	result=0;
	i=0;
	while(num)
	{
	    if((num&1)==0)
	    {
	        result= result + (1<<i);
	    }
	    
	    i++;
	    num=num>>1;
	    
	 }
	 
	 cout<<"1s compliment "<<result;
	 cout<<"\n2s compliment "<<result+1;
	return 0;
}