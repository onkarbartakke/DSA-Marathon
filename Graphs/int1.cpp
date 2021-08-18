#include<iostream>

using namespace std;

int main()
{
    int diff=INT_MAX;
    int n;
    /*
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                int cur_sum=a[i]+a[j]+a[k];

            }
        }
    }

    */

    sort(a,a+n);
    int val;
    for(i=0;i<n;i++)
    {
        int sum=val-a[i];
        j=i+1;
        k=n-1;


        while(j<=k)
        {
            if(a[j]+a[k]==sum)
            {
               res=a[i]+sum;
                break;
            }
            curr_diff=abs(sum-(a[j]+a[k]));
            if(curr_diff < diff)
            {
                diff=curr_diff;
                res=a[i]+sum;
            }

            if(a[j]+a[k] > sum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }

    }

    cout<<res;
}