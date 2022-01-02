#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
    unordered_map<int, TreeNode *> mp;
    unordered_map<int, int> cnt;

    bool traverse(TreeNode *t, unordered_map<int, TreeNode *> &mp, TreeNode *left = NULL, TreeNode *right = NULL)
    {
        if (t == NULL)
            return true;

        if ((left && t->val <= left->val) || (right && t->val >= right->val))
            return false;

        if (t->left == t->right)
        {
            auto it = mp.find(t->val);

            if (it != mp.end() && t != it->second)
            {
                t->left = it->second->left;
                t->right = it->second->right;
                mp.erase(it);
            }
        }

        return traverse(t->left, mp, left, t) && traverse(t->right, mp, t, right);
    }
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {

        for (auto it : trees)
        {
            mp[it->val] = it;
            cnt[it->val]++;

            if (it->left)
            {
                cnt[it->left->val]++;
            }

            if (it->right)
            {
                cnt[it->right->val]++;
            }
        }

        for (auto it : trees)
        {
            if (cnt[it->val] == 1)
            {
                if (traverse(it, mp) && mp.size() == 1)
                    return it;
                else
                    return NULL;
            }
        }

        return NULL;
    }

    bool traverse1(TreeNode *r, unordered_map<int, TreeNode *> &m, int min_left = INT_MIN, int max_right = INT_MAX)
    {
        if (r == nullptr)
            return true;
        if (r->val <= min_left || r->val >= max_right)
            return false;
        if (r->left == r->right)
        {
            auto it = m.find(r->val);
            if (it != end(m) && r != it->second)
            {
                r->left = it->second->left;
                r->right = it->second->right;
                m.erase(it);
            }
        }
        return traverse1(r->left, m, min_left, r->val) && traverse1(r->right, m, r->val, max_right);
    }


    TreeNode *canMerge1(vector<TreeNode *> &trees)
    {
        unordered_map<int, TreeNode *> m;
        unordered_map<int, int> cnt;
        for (auto &t : trees)
        {
            m[t->val] = t;
            ++cnt[t->val];
            ++cnt[t->left ? t->left->val : 0];
            ++cnt[t->right ? t->right->val : 0];
        }
        for (auto &t : trees)
            if (cnt[t->val] == 1)
                return traverse1(t, m) && m.size() == 1 ? t : nullptr;
        return nullptr;
    }
};

int main()
{
}