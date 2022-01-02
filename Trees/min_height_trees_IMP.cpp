#include <bits/stdc++.h>

using namespace std;
/*

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/

/*
Approach 
So what we do here is that to get the min height tree, basically we need the longest the path in tree between any 2 leaf nodes, 
the middle part of that longest part will be our ans, basically min possible height of any tree that we can get is half of the longest path between 
leaf nodes, so the root will be middle part (1 node if odd len path and 2 nodes if even len path)

Now lets suppose we somehow get the longest possible  path between any 2 nodes, how will u reach it's mid?
well if u start chopping of the leaves from both the ends one by one eventually u will reach mid.

Now if you start chopping off all the possible leaves, at last we will left with the middle of the longest possible path between any 2 leaf nodes
why?

as we chop off 1 leaf node , the node above it becomes a leaf node, as the path is longest at last we will end up getting on that path 
if start chopping all the leaf nodes one by one in each iteration.

*/
class Solution
{
    public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        vector<int> ans;
        if (n == 1)
        {
            ans.push_back(0);
            return ans;
        }

        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        queue<int> qu;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                qu.push(i);
                ans.push_back(i);
                indegree[i]--;
            }
        }

        while (!qu.empty())
        {
            ans.clear();
            int sz = qu.size();

            for (int i = 0; i < sz; i++)
            {
                int node = qu.front();
                qu.pop();

                ans.push_back(node);

                for (auto it : adj[node])
                {
                    indegree[it]--;

                    if (indegree[it] == 1)
                    {
                        qu.push(it);
                    }
                }
            }
        }

        return ans;
    }
};