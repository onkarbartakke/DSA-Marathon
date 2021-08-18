#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tandemBicycle(vector<int> red, vector<int> blue,
                  bool fastest) {
  // Write your code here.
	sort(red.begin(),red.end());
	sort(blue.begin(),blue.end());
	int totalspeed;
	int r=red.size();
	int b=blue.size();
	if(fastest)
	{
		int i,j,m,n;
		int speed=0;
		i=r-1;
		j=b-1;
		
		n=0; //red
		m=0;  //blue
		
		while(i>=n && j>=m)
		{
			if(red[i] > blue[j])
			{
					speed+=red[i];
					i--;
					m++;
			}
			else
			{
				speed+=blue[j];
				j--;
				n++;
			}
		}
		
		return speed;
	}
	else
	{
		int i,j,m,n;
		int speed=0;
		i=r-1;
		j=b-1;
		
		n=0; //red
		m=0;  //blue
	
		while(i>=0)
		{
			speed+=(max(red[i],blue[i]));
			i--;
		}
		
		return speed;
	}
  return -1;
}
