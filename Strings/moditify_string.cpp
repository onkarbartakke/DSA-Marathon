#include <bits/stdc++.h>

using namespace std;

// string getString(string s)
// {
//     reverse(s.begin(), s.end());

//     string ans = "0";

//     vector<int> cnt(256, 0);

//     for (auto c : s)
//         cnt[c]++;

//     vector<int> visited(256, false);
//     for (auto c : s)
//     {
//         cnt[c]--;

//         if (visited[c])
//             continue;

//         while (c < ans.back() && cnt[ans.back()] > 0)
//         {
//             visited[ans.back()] = false;
//             //  cnt[ans.back()]++;

//             ans.pop_back();
//         }

//         ans += c;
//         visited[c] = true;
//     }

//     string ret = ans.substr(1);

//     reverse(ret.begin(), ret.end());

//     return ret;
// }


string getString(string s)
{
    int n = s.length();
    stack<char> st;

    vector<int> visited(26, 0), cnt(26, 0);

    
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++)
    {

        
        cnt[s[i] - 'a']--;

        if (visited[s[i] - 'a'])
        {
            continue;
        }

        while (!st.empty() && st.top() < s[i] && cnt[st.top() - 'a'] != 0)
        {
            visited[st.top() - 'a'] = 0;
            st.pop();
        }

       
        st.push(s[i]);
        visited[s[i] - 'a'] = 1;
    }

    
    string s1;

   
    while (!st.empty())
    {
        s1 = st.top() + s1;
        st.pop();
    }

    return s1;
}


int processors(int n, int m, int k)
{
    
}
int main()
{
    string s;
    cin>>s;

    cout<<getString(s);
}