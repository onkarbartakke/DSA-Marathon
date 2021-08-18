#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> st;
    int i;
    for (i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b] == 1)
        {
            st.push(b);
        }
        else if (M[a][b] == 0)
        {
            st.push(a);
        }
    }

    if (st.size() == 0)
        return -1;

    int c = st.top();

    for (i = 0; i < n; i++)
    {
        if (i != c && (M[c][i] == 1 || M[i][c] == 0))
            return -1;
    }

    return c;
}

int main()
{
}