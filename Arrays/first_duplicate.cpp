#include<iostream>
#include<vector>

using namespace std;

int firstDuplicateValue(vector<int> a) { 
	int n,i,j;
	n=a.size();
	
	for(i=0;i<n;i++)
	{
		int k=a[i];
		
		int x = a[(int)abs(k)];
		 if(x < 0)
			return (int)abs(k);
		else
			a[(int)abs(k)]=-1*a[(int)abs(k)];
	}
	
	return -1;
}

int main()
{
    int n,i;
    cin>>n;
    vector<int>a(n);

    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<"\n"<<firstDuplicateValue(a);
}