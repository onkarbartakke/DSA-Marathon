#include <bits/stdc++.h>

using namespace std;

// Brute Force, fails when tree is like a long chain of nodes due to TLE
/*
class TreeAncestor {
public:
    int n;
    vector<int>p;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        this->p = parent;
    }
    
    int getKthAncestor(int node, int k) {
        
        if(k==0)
            return node;
        int par;
        while(k)
        {
            node = p[node];
            k--;
            
            if(node==-1)
                return node;
        }
        
        return node;
        
    }
};
*/
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
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

        //          for (int i = 0; i < 20; i++) {
        //             if ((k >> i) & 1) {
        //                 node = up[node][i];
        //                 if (node == -1) return -1;
        //             }
        //         }
        //         return node;
    }
};
/*
  for (int i = 0; i < 20; i++) {
            if ((k >> i) & 1) {
                node = v[node][i];
                if (node == -1) return -1;
            }
        }
        return node;
        */
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

/*
ok so there is concept of binary lifting,
what is binary lifting ??

So any number can be expressed power of 2,
and we can greedily find that ,
by taking highest powers and taking the modulo,
or just utilising the inbuilt binary format that
how numbers are stored in computer,
so we know how to represent k in binary format,
so now using the same concept we will jump on k height using binary powers,
and remove the highest power ,
but here we must know the 2^i th height parent from every node,
so we will preprocess the tree as shown in the code,
so u could see as 2^i = 2^(i-1) + 2^(i-1),
so if we calculated 2^(i-1) th parent of every node beforehand
we could calculate 2^i th parent from that,
like 2^(i-1) th parent of 2^(i-1) th parent of the node,
right like 4th parent is 2nd parent of 2nd parent of node,
this is called binary lifting.

so now utilise the binary version of k and jump accordingly.
I have also made parent of 0 to -1,
so that I could stop if I went above the node.
*/