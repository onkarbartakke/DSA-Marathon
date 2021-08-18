#include<iostream>
#include<vector>
using namespace std;

int minSwaps(vector<int> &nums)
{
    // Code here
    int i, j, k;
    int n = nums.size();
    pair<int, int> arrpair[n];

    for (i = 0; i < n; i++)
    {
        arrpair[i].first = nums[i];
        arrpair[i].second = i;
    }

    sort(arrpair, arrpair + n);

    vector<bool> vis(n, false);
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        if (vis[i] || nums[i] == arrpair[i].first)
            continue;

        int cycle_size = 0;
        j = i;
        while (!vis[j])
        {
            vis[j] = true;
            cycle_size++;

            j = arrpair[j].second;
        }

        if (cycle_size > 0)
        {
            ans = ans + (cycle_size - 1);
        }
    }

    return ans;
}

int main()
{
    int n,i;
    cout<<"Enter the num of elements : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"\nEnter the Elements : \n";

    for(i=0;i<n;i++)
    cin>>nums[i];

    int swaps=minSwaps(nums);
    cout<<"\nMin swaps required are : "<<swaps;
}