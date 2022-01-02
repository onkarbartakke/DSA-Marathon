#include <bits/stdc++.h>

using namespace std;

// You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

// A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

// The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end),
//the range of real numbers x such that start <= x < end.

// Implement the MyCalendarTwo class:

// MyCalendarTwo() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without
// causing a triple booking. Otherwise, return false and do not add the event to the calendar.

// We can store the frequency of intervals in the dynamic segment tree. While doing query for given interval
// we return the max number of intervals in that given range and if it 2 we can not insert it to tree otherwise
// we insert the interval in the segment tree.

// As total array is not given at first we have to use synamic segment tree with initial range 0 and 10E9.
// We keep dividing the node ranges and check the mid value with given range and we move left or right or
// both subtree. We stop as soon as we get a match for min and max range of node and given interval.
// In case of query we return the node value which stores the frequency count of the intervals in that range
// and in case of update we update the node value and node lazy value. Lazy value of any node  is used
// as a future update for its child nodes which has not yet been accessed.
class MyCalendarTwo
{
    public:
    // tree node stores left, right, value and lazy value
    struct Node
    {
        int val;
        int lazy;
        Node *left;
        Node *right;
    };

    // create tree node
    Node *createNode()
    {
        Node *node = new Node();
        node->val = 0;
        node->lazy = 0;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    // tree root
    Node *root;

    // max range of the segment tree and root range (0,LIMIT)
    int LIMIT = 1000000001;

    MyCalendarTwo()
    {

        // create root node
        root = createNode();
    }

    // return the max frequency of intervals for given interval in the segment tree
    int query(Node *node, int minRange, int maxRange, int low, int high)
    {
        // create child nodes if NULL
        if (!node->left)
            node->left = createNode();
        if (!node->right)
            node->right = createNode();

        // update lazy value with the node value and propagate the lazy value to the child nodes lazy value if node range is not a single point
        if (node->lazy != 0)
        {
            node->val += node->lazy;
            if (minRange != maxRange)
            {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;
        }

        // node range out of given range and so return 0
        if (maxRange < low || minRange > high)
            return 0;

        // node range completely overlap with given range and so return node value
        if (minRange >= low && maxRange <= high)
            return node->val;

        // get mid value of the node range
        int mid = minRange + (maxRange - minRange) / 2;

        // current range partial overlap with node range and so divide in to 2 subtree and return their max value
        return max(query(node->left, minRange, mid, low, high), query(node->right, mid + 1, maxRange, low, high));
    }

    // update the frequency of the nodes of segment tree which range fall in the given range
    void updateVal(Node *node, int minRange, int maxRange, int low, int high)
    {

        // create child nodes if NULL
        if (!node->left)
            node->left = createNode();
        if (!node->right)
            node->right = createNode();

        // update lazy value with the node value and propagate the lazy value to the child nodes lazy value if node range is not a single point
        if (node->lazy != 0)
        {
            node->val += node->lazy;
            if (minRange != maxRange)
            {
                node->left->lazy += node->lazy;
                node->right->lazy += node->lazy;
            }
            node->lazy = 0;
        }

        // node range out of given range and so return
        if (maxRange < low || minRange > high)
            return;

        // node range completely overlap with given range then update node value and
        // propagate the new  value to the child nodes lazy value if node range is not a single point
        if (minRange >= low && maxRange <= high)
        {
            node->val++;
            if (minRange != maxRange)
            {
                node->left->lazy++;
                node->right->lazy++;
            }

            return;
        }

        // get mid value of the node range
        int mid = minRange + (maxRange - minRange) / 2;

        // current range partial overlap with node range and so divide in to 2 subtree
        updateVal(node->left, minRange, mid, low, high);
        updateVal(node->right, mid + 1, maxRange, low, high);

        // update current node value from max of child nodes
        node->val = max(node->left->val, node->right->val);
    }

    bool book(int start, int end)
    {

        // check if given range can be inserted in the segment tree if interval count < 2 otherwise can not insert
        if (query(root, 0, LIMIT, start, end - 1) == 2)
            return false;

        // update segment tree with given range
        updateVal(root, 0, LIMIT, start, end - 1);
        return true;
    }
};
