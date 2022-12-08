#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    char data;
    int freq;
    bool isLeaf;
    Node *left;
    Node *right;

    Node(char c = '/', int f = 0)
    {
        data = c;
        freq = f;

        if (c == '/')
            isLeaf = false;
        else if (c != '/' && f > 0)
            isLeaf = true;

        left = NULL;
        right = NULL;
    }
};

class mycomp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->freq > b->freq);
        // For Min Heap
    }
};

void preorder(Node *t, string s, vector<string> &ans)
{
    if (t == NULL)
        return;

    if (t->isLeaf)
    {
        ans.push_back(s);

        return;
    }

    preorder(t->left, s + "0", ans);
    preorder(t->right, s + "1", ans);
}
vector<string> huffmanCodes(string S, vector<int> f, int N)
{
    // Code here

    priority_queue<Node *, vector<Node *>, mycomp> pq;

    int i, j, k;

    for (i = 0; i < N; i++)
    {
        Node *t = new Node(S[i], f[i]);

        pq.push(t);
    }

    while (pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();

        Node *r = pq.top();
        pq.pop();

        char c = '/';
        int f = l->freq + r->freq;
        Node *t = new Node(c, f);
        t->isLeaf = false;

        t->left = l;
        t->right = r;

        pq.push(t);
    }

    vector<string> ans;

    Node *root = pq.top();

    stack<Node *> st;

    Node *p = root;

    string s = "";
    preorder(p, s, ans);

    return ans;
}

int main()
{
}