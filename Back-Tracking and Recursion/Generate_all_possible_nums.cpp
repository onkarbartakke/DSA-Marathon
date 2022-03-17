#include<bits/stdc++.h>

using namespace std;
/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ],
 the task is to list all words which are possible by pressing these numbers.
*/
void Generate(int a[], int pos, int N, string &s, vector<string> &ans, unordered_map<int, string> mp)
{
    if (pos >= N)
    {
        ans.push_back(s);
        return;
    }

    string curr = mp[a[pos]];

    int len = curr.length();
    for (int i = 0; i < len; i++)
    {
        s.push_back(curr[i]);
        Generate(a, pos + 1, N, s, ans, mp);
        s.pop_back();
    }

    return;
}
vector<string> possibleWords(int a[], int N)
{
    //Your code here
    unordered_map<int, string> mp;

    mp[2] = "abc";
    mp[3] = "def";
    mp[4] = "ghi";
    mp[5] = "jkl";
    mp[6] = "mno";
    mp[7] = "pqrs";
    mp[8] = "tuv";
    mp[9] = "wxyz";

    vector<string> ans;

    string s = "";
    Generate(a, 0, N, s, ans, mp);

    return ans;
}