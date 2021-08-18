#include <bits/stdc++.h>
#include <iostream>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long int n,i,j,m;
        cin>>n;
        long long int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        sort(a,a+n);
        i=0;
        j=m-1;
        long long int min_diff=INT_MAX;
        long long int diff;
        while(j<n)
        {
            diff=a[j]-a[i];
            min_diff=min(min_diff,diff);
            i++;
            j++;
        }
        
        cout<<min_diff<<"\n";
        
    }
	return 0;
}