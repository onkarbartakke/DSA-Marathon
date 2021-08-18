#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());

    stack<vector<int>> st;

    st.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> tp = st.top();

        if (tp[1] < intervals[i][0])
            st.push(intervals[i]);
        else
        {
            if (tp[1] < intervals[i][1])
            {
                tp[1] = intervals[i][1];
            }
            st.pop();
            st.push(tp);
        }
    }

    vector<vector<int>> ans;

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main()
{
}