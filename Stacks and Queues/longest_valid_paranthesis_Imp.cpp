#include <bits/stdc++.h>

using namespace std;
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
 
parentheses substring.

 
 */
class Solution
{
public:
    int longestValidParentheses(string s)
    {

        stack<int> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (!st.empty() && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(i);
            }
        }

        if (st.empty())
            return s.length();

        int longest = 0;
        int left, right;
        right = s.length();
        while (!st.empty())
        {
            left = st.top();
            st.pop();

            longest = max(longest, right - left - 1);
            right = left;
        }

        longest = max(right, longest);

        return longest;
    }
};

/*
The workflow of the solution is as below.

Scan the string from beginning to end.
If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.
After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.
If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3.
*/