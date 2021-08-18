#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
bool cmp(Item a,Item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    
    return r1>r2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // Your code here
    int i,j,k;
    
    sort(arr,arr+n,cmp);
    
    double currwt,currvalue;
    currwt=0;
    currvalue=0;
    for(i=0;i<n;i++)
    {
        if(currwt+arr[i].weight<W)
        {
            currwt=currwt+arr[i].weight;
            currvalue=currvalue+arr[i].value;
        }
        else
        {
            double remainwt=W-currwt;
            currvalue=currvalue+arr[i].value*(remainwt/(double)arr[i].weight);
            break;
        }
    }
    
    return currvalue;
}
