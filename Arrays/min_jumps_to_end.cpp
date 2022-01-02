#include<iostream>
#include<climits>

using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    int *jump;
    int i,j;
    jump=new int [n];
    jump[0]=0;
    if(n==0 || arr[0]==0)
    {
        return -1;
    }
    
    for(i=1;i<n;i++)
    {
        jump[i]=INT_MAX;
        for(j=0;j<i;j++)
        {
            if(i<=j+arr[j] && jump[j]!=INT_MAX)
            {
                jump[i]=min(jump[j]+1,jump[i]);
                break;
            }
        }
    }
    
    if(jump[n-1]==INT_MAX)
    return -1;
    else
    return jump[n-1];
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends