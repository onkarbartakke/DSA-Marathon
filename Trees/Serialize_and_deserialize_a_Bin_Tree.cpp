#include <bits/stdc++.h>

using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

/*
Serialization is the process of converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, or transmitted across a network connection link 
to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be 
serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
*/
class Codec
{
public:
    // Encodes a tree to a single string.

    void Traverse(TreeNode *r, string &ans)
    {
        if (r == NULL)
        {
            ans += "N,";
            return;
        }

        string s = to_string(r->val);
        ans += s;
        ans += ",";

        Traverse(r->left, ans);
        Traverse(r->right, ans);
    }

    string serialize(TreeNode *root)
    {

        string ans = "";

        Traverse(root, ans);

        return ans;
    }

    // Decodes your encoded data to tree.

    TreeNode *BuildTree(string data, int &pos)
    {
        if (pos >= data.size())
            return NULL;

        if (data[pos] == ',')
            pos++;

        if (data[pos] == 'N')
        {
            pos++;
            return NULL;
        }

        string s = "";

        while (pos < data.size() && data[pos] != ',' && data[pos] != 'N')
        {
            s.push_back(data[pos]);
            pos++;
        }

        int n = stoi(s);

        TreeNode *r = new TreeNode(n);

        if (data[pos] == ',')
            pos++;

        r->left = BuildTree(data, pos);
        r->right = BuildTree(data, pos);

        return r;
    }
    TreeNode *deserialize(string data)
    {

        int pos = 0;

        TreeNode *r = NULL;

        if (data[pos] == 'N')
            return r;

        string s;

        while (pos < data.size() && data[pos] != ',' && data[pos] != 'N')
        {
            s.push_back(data[pos]);
            pos++;
        }

        int n = stoi(s);

        r = new TreeNode(n);

        if (data[pos] == ',')
            pos++;

        r->left = BuildTree(data, pos);
        r->right = BuildTree(data, pos);
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));