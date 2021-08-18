#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool mycmp(pair<int, int>p1, pair<int, int>p2)
{
    return p1.first<p2.first;
}


int main() {
	
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	vector< pair<int, int> >v;
	for(i=0;i<n;i++)
	{
	    pair<int, int>p;
	    
	    p.first=a[i];
	    p.second=i;
	    v.push_back(p);
	    
	    //can also be done by inbuilt function
	    // v.push_back(make_pair(a[i],i));
	}
	
	
	sort(v.begin(),v.end(),mycmp);
	
	for(i=0;i<v.size();i++)
	{
	    a[v[i].second]=i;
	}
	
	
	for(i=0;i<n;i++)
	{
	    cout<<a[i]<<" ";
	}
	return 0;
}