#include<iostream>
#include<queue>
#include<set>
// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    //code here

    //Heap approach
    /*
        priority_queue<int,vector<int>,greater<int>>minh;
        
        for(int i=l;i<=r;i++)
        {
            minh.push(arr[i]);
        }
        
        int count=0;
        
        int ans;
        while(count<k)
        {
            ans=minh.top();
            minh.pop();
            count++;
            
            if(count==k)
            return ans;
        }
      */
     //Set approach
     int n = r-l+1;
    set<int> s(arr, arr + n);
    set<int>::iterator itr = s.begin(); // s.begin() returns a pointer to first
                                        // element in the set
    advance(itr, k - 1);                // itr points to kth element in set

    return (*itr);
}