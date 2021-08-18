#include <iostream>
#include <string.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

class AncestralTree
{
    public:
    char name;
    AncestralTree *ancestor;

    AncestralTree(char name)
    {
        this->name = name;
        this->ancestor = nullptr;
    }

    void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,AncestralTree *descendantOne, AncestralTree *descendantTwo)
{

    set<AncestralTree *> st;

    AncestralTree *n1 = descendantOne;
    AncestralTree *n2 = descendantTwo;

    while (n1)
    {
        st.insert(n1);
        n1 = n1->ancestor;
    }

    while (n2)
    {
        if (st.find(n2) != st.end())
        {
            return n2;
        }

        n2 = n2->ancestor;
    }

    // Write your code here.
    return nullptr;
}
