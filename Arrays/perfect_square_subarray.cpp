#include<iostream>

using namespace std;

int count_subarray_perfect_sq(int a[], int n)
{
    int min_sum, cumm_sum, count, i,j;
    min_sum=0;
    cumm_sum=0;
    count=0;

    int hash_pos[1000]={0};
    int hash_neg[1000]={0};
    hash_pos[0]=1;

    for(i=0;i<n;i++)
    {
        cumm_sum=cumm_sum+a[i];
        min_sum=min(min_sum,cumm_sum);

        j=0;
        while(cumm_sum-(j*j)>=min_sum)
        {
            if(cumm_sum-(j*j)>=0)
            {
                count=count+hash_pos[cumm_sum-(j*j)];
            }
            else
            {
                count=count+ hash_neg[-1*(cumm_sum-(j*j))];
            }

            j++;
        }

        if(cumm_sum>=0)
        hash_pos[cumm_sum]++;
        else
        hash_neg[-1*cumm_sum]++;
    }


    return count;
}

int main()
{
    int n,i;
    cout<<"Enter the num of elements in array : ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements : ";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int ans=count_subarray_perfect_sq(a,n);
    cout<<"\n"<<ans;

    return 0;
}