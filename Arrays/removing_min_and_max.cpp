#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int minimumDeletions(vector<int> &nums)
    {

        int n = nums.size();
        int i = min_element(nums.begin(), nums.end()) - nums.begin();
        int j = max_element(nums.begin(), nums.end()) - nums.begin();

        if (i > j)
            swap(i, j);

        return min(i + 1 + n - j, min(j + 1, n - i));
    }
};