#include <bits/stdc++.h>

using namespace std;
/*
Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {

        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                count++;
            else if (s[i] == ')')
            {
                if (count > 0)
                    count--;
                else
                    s[i] = '#';
            }
        }

        count = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                count++;
            else if (s[i] == '(')
            {
                if (count > 0)
                    count--;
                else
                    s[i] = '#';
            }
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
                continue;

            ans.push_back(s[i]);
        }

        return ans;
    }
};


bool check(node *root){
      if(root ==NULL)
      return true;

      if(root->right && root->data > root->right->data)
      return false;

      if(root->left && root->data < root->left->data)
      return false;
     
      bool left,right;
        left=  check(root->left);
        right =  check(root->right);
      cout<<"true";
      return (left && right);     
}