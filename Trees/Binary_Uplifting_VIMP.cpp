#include <bits/stdc++.h>

using namespace std;

/*
You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is
the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.

The kth ancestor of a tree node is the kth node in the path from that node to the root node.

Implement the TreeAncestor class:

TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor,
return -1.

 */
class TreeAncestor
{
public:
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int> &parent)
    {

        up = vector<vector<int>>(n, vector<int>(20));

        for (int v = 0; v < n; v++)
            up[v][0] = parent[v];

        for (int v = 0; v < n; v++)
        {

            for (int j = 1; j < 20; j++)
            {
                if (up[v][j - 1] == -1)
                    up[v][j] = -1;
                else
                    up[v][j] = up[up[v][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        int i = 0;
        while (k >> i)
        {
            if ((k >> i) & 1)
            {
                node = up[node][i];

                if (node == -1)
                    return node;
            }

            i++;
        }

        return node;
    }
};
int main()
{
}