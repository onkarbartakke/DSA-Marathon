#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    // code here
    int i;
    string t = "";
    vector<vector<string>> ans;
    for (i = 0; i < s.size(); i++)
    {
        t += s[i];
        vector<string> v;
        set<string> st;
        for (int j = 0; j < n; j++)
        {
            int l = contact[j].find(t);
            if (l == 0)
            {
                st.insert(contact[j]);
            }
        }
        if (!st.empty())
        {
            for (auto it : st)
            {
                v.push_back(it);
            }
            ans.push_back(v);
        }
        else
        {
            v.push_back("0");
            ans.push_back(v);
        }
    }
    return ans;
}

/*
Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. 
The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s 
(i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. 
Please refer the explanation part for better understanding.
Note: If there is no match between query and contacts, print "0".

Example 1:

Input: 
n = 3
contact[] = {"geeikistest", "geeksforgeeks", 
"geeksfortest"}
s = "geeips"
Output:
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explaination: By running the search query on 
contact list for "g" we get: "geeikistest", 
"geeksforgeeks" and "geeksfortest".
By running the search query on contact list 
for "ge" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "gee" we get: "geeikistest" "geeksforgeeks"
and "geeksfortest".
By running the search query on contact list 
for "geei" we get: "geeikistest".
No results found for "geeip", so print "0". 
No results found for "geeips", so print "0".
Your Task:
Youd do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as
input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that 
list.

Expected Time Complexity: O(|s| * n * max|contact[i]|)
Expected Auxiliary Space: O(n * max|contact[i]|)
*/