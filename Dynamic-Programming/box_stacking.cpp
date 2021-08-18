#include<iostream>
#include<algorithm>

using namespace std;

class Box
{
    public:
        int len;
        int bre;
        int ht;
};

bool mycomp(Box b1, Box b2)
{
    return b1.len*b1.bre > b2.bre*b2.len;
}

void generate_rotations(Box arr[], int n, Box rots[])
{
    int i,index=0;
    for(i=0;i<n;i++)
    {
        rots[index].ht=arr[i].ht;
        rots[index].len=max(arr[i].len,arr[i].bre);
        rots[index].bre=min(arr[i].len,arr[i].bre);
        index++;

        rots[index].ht=arr[i].len;
        rots[index].len=max(arr[i].ht,arr[i].bre);
        rots[index].bre=min(arr[i].ht,arr[i].bre);
        index++;

        rots[index].ht=arr[i].bre;
        rots[index].len=max(arr[i].ht,arr[i].len);
        rots[index].bre=min(arr[i].ht,arr[i].len);
        index++;
    }
}

int max_stack_height(Box rots[], int m)
{
    int i,j,k;
    int h[m];
    for(i=0;i<m;i++)
    {
        h[i]=rots[i].ht;
    }


    for(i=1;i<m;i++)
    {
        for(j=0;j<i;j++)
        {
            if(rots[i].len < rots[j].len && rots[i].bre < rots[j].bre && h[i] < h[j]+rots[i].ht)
            {
                h[i]=h[j]+rots[i].ht;
            }
        }
    }

    int max=0;

    for(i=0;i<m;i++)
    {
        if(max<h[i])
        max=h[i];
    }

    return max;
}

int main()
{
    int n,i,l;
    cout<<"Enter the Number of boxes: ";
    cin>>n;

    cout<<"\nEnter Dimension(l,b,h) of boxex : \n";

    Box arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i].len>>arr[i].bre>>arr[i].ht;
    }
    int m=3*n;
    Box rots[m];
    generate_rotations(arr,n,rots);

    sort(rots,rots+m,mycomp);


    int ans=max_stack_height(rots,m);

    cout<<"\nMax height reached is : "<<ans;
}