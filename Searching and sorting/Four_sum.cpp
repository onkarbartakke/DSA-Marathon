#include <bits/stdc++.h>

using namespace std;
/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.
*/

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    /*
        vector<vector<int>>ans;
        unordered_map<int, vector<pair<int,int>>>mp;
        int n=arr.size();
        int i,j;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                mp[arr[i]+arr[j]].push_back({i,j});
            }
        }
        
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int sum=arr[i]+arr[j];
                
                if(mp.find(k-sum)!=mp.end())
                {
                    vector<pair<int,int>>v=mp[k-sum];
                    vector<pair<int,int>>::iterator it=v.begin();
                    for(it=v.begin();it!=v.end();it++)
                    {
                        if(it->first!=i && it->second!=i && it->first!=j && it->second!=j)
                        {
                            vector<int>v1;
                            v1.push_back(arr[i]);
                            v1.push_back(arr[j]);
                            v1.push_back(arr[it->first]);
                            v1.push_back(arr[it->second]);
                            
                            sort(v1.begin(),v1.end());
                            
                            ans.push_back(v1);
                        }
                    }
                }
            }
        }
        
        
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()), ans.end());
        
        return ans;
        */

    vector<vector<int>> v;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 3; i++)
    {
        for (int j = i + 1; j < arr.size() - 2; j++)
        {
            int l = j + 1;
            int r = arr.size() - 1;
            while (l < r)
            {
                vector<int> v1;
                if (arr[i] + arr[j] + arr[l] + arr[r] == k)
                {
                    v1.push_back(arr[i]);
                    v1.push_back(arr[j]);
                    v1.push_back(arr[l]);
                    v1.push_back(arr[r]);

                    v.push_back(v1);
                    l++;
                    r--;
                }
                else if (arr[i] + arr[j] + arr[l] + arr[r] < k)
                    l++;
                else
                    r--;
            }
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}
int main()
{
}

/*
std::unique is used to remove duplicates of any element present consecutively in a range[first, last). It performs this task for all the 
sub-groups present in the range having the same element present consecutively.

It does not delete all the duplicate elements, but it removes duplicacy by just replacing those elements by the next element present 
in the sequence which is not duplicate to the current element being replaced. All the elements which are replaced are left in
 an unspecified 
state.
Another interesting feature of this function is that it does not changes the size of the container after deleting the elements,
 it just returns a pointer pointing to the new end of the container, and based upon that we have to resize the container,
  or remove the garbage elements.
*/