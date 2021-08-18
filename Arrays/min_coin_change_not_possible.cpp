#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
	sort(coins.begin(),coins.end());
	
	int minCoinChange=0;
	
	for(auto i : coins)
	{
		if(minCoinChange + 1 < i)
			return minCoinChange +1 ;
		
		minCoinChange+=i;
	}
  return minCoinChange+1;
}
