#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> st;

        for (auto it : nums)
            st.insert(it);

        int count = 0;
        int curr;
        for (auto n : nums)
        {
            if (st.find(n - 1) != st.end())
                continue;
            else
            {
                curr = 0;

                while (st.find(n) != st.end())
                {
                    curr++;
                    n++;
                }

                count = max(count, curr);
            }
        }

        return count;
    }
};
