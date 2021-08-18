#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findMaxLen(string s)
{
    // code here
    int i, ans = 0;
    stack<int> st;
    st.push(-1);
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (!st.empty())
                st.pop();

            if (!st.empty())
            {
                ans = max(ans, i - st.top());
            }

            if (st.empty())
                st.push(i);
        }
    }

    return ans;
}
int main()
{
    string s;
    cin>>s;
    int l=findMaxLen(s);

    cout<<"\n"<<l;
}