#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,j,k;

    cout<<"Enter the num of Barns : ";
    cin>>n;
    cout<<"\nEnter the locations of Barns : \n";
    int loc[n];

    for(i=0;i<n;i++)
    cin>>loc[i];

    sort(loc,loc+n);

    cout<<"\nEnter num of cows : ";
    int c;
    cin>>c;

    int low=0, high=loc[n-1], mid, cnt, left;
    int best;
    mid=(low+high+1)/2;

    while(low<=high)
    {
        cnt=1;
        left=0;
        for(i=1;i<n;i++)
        {
            if(loc[i]-loc[left]>=mid)
            {
                cnt++;
                left=i;

                if(cnt>=c)
                break;
            }
        }

        if(cnt>=c)
        {
            best=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        
    }

    cout<<"\nMax of mini distance is : "<<best;
}