#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int laptopRentals(vector<vector<int>> times) {
  // Write your code here.
	int count=0;
	int m=0;
	
	sort(times.begin(),times.end());
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
	
	int n=times.size();
	
	for(int i=0;i<n;i++)
	{
		if(pq.empty())
		{
			pq.push({times[i][1],times[i][0]});
			count++;
		}
		else
		{
			pair<int,int>p=pq.top();
			if(times[i][0] < p.first)
			{
				count++;
			
			}
			else
			{
				pq.pop();
			}
			
				pq.push({times[i][1],times[i][0]});
		}
	}
	
	return count;

}


int main()
{
    
}