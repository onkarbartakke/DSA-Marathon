#include<bits/stdc++.h>

using namespace std;
/*
This can be done in O(n) time by doing a single traversal of given array. 
The idea is based on the fact that if we make sure that all even positioned (at index 0, 2, 4, ..) 
elements are greater than their adjacent odd elements, we don’t need to worry about odd positioned element. 
Following are simple steps. 
1) Traverse all even positioned elements of input array, and do following. 
….a) If current element is smaller than previous odd element, swap previous and current. 
….b) If current element is smaller than next odd element, swap next and current.

Below are implementations of above simple algorithm. 

*/
void WiggleSort(vector<int>&A)
{
    int n = A.size();

    for(int i = 0 ; i < n ; i += 2)
    {
        if(i>0 && A[i]<A[i-1])
        swap(A[i],A[i-1]);

        if(i<n-1 && A[i] < A[i+1])
        swap(A[i],A[i+1]);
    }
}
int main()
{
    int n;
    cin>>n;

    vector<int>A(n);

    for(int i = 0 ;  i < n ; i++)
    cin>>A[i];

    WiggleSort(A);


    cout<<"\n\n";

    for(int i = 0 ; i < n ; i++)
    cout<<A[i]<<" ";
}