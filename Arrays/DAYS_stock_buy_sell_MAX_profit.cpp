#include <iostream>
using namespace std;

int main() {
	int n,i;
	cin>>n;
	int price[n];
	int buy,sell;
	for(i=0;i<n;i++)
	{
	    cin>>price[i];
	}
	i=0;
	while(i<n-1)
	{
	   while((i<n-1) && price[i+1]<=price[i])   //code is simple, algo is IMP
	   i++;
	                                               //observation of peaks and valleys matters
	   if(i==n-1)
	   break;
	   
	   buy=i;
	   i++;
	   
	   while((i<n) && price[i-1]<=price[i])
	   i++;
	   
	   sell=i-1;
	   
	   
	   cout<<"Buy on day - "<<buy<<" Sell on that- "<<sell<<"\n";
	}
	return 0;
}