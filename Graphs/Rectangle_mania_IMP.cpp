#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include<unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

int rectangleMania(vector<vector<int>> coords) {
  // Write your code here.
	set< vector<int> >st;
	int i,j,n;
	n=coords.size();
	for(i=0;i<n;i++)
	{
		st.insert(coords[i]);
	}
	int count=0;
	for(i=0;i<n-1;i++)
	{
		int x1,y1,x2,y2;
		x1=coords[i][0];
		y1=coords[i][1];
		for(j=i+1;j<n;j++)
		{
			x2=coords[j][0];
			y2=coords[j][1];
			
			if((x2>x1 && y2>y1) || (x1>x2 && y1>y2)  )  //Upper Right
			{
				if(st.find({x1,y2})!=st.end() && st.find({x2,y1})!=st.end() )
				{
					count++;
				}
			}
		}
	}
	
	
  return (count);
}


int main()
{

}


/*

Given coords of points, return num f rectangkes that can be formed which are parallel with x and y axis
*/