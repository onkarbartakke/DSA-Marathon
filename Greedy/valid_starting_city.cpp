#include<iostream>
#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) {
  // Write your code here.
	int n,i,j;
	n=distances.size();
	int currfuel=0;
	int start=0;
	for(i=0;i<n;i++)
	{
		currfuel+=((fuel[i]*mpg)-(distances[i]));
		
		if(currfuel >=0)
			continue;
		else
		{
			currfuel=0;
			start=(i+1)%n;
		}
		
	}
  return start;
}

int main()
{
    
}