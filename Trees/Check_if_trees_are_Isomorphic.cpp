#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d = 0)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

/*
We simultaneously traverse both trees. Let the current internal nodes of two trees being traversed be n1 and n2
 respectively. There are following two conditions for subtrees rooted with n1 and n2 to be isomorphic.
1) Data of n1 and n2 is same.
2) One of the following two is true for children of n1 and n2
……a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2.
……b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.
*/

bool isIsomorphic(Node *root1, Node *root2)
{
    //add code here.
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    bool check1 = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);

    if (check1)
        return true;

    bool check2 = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);

    return check2;
}

int main()
{
}