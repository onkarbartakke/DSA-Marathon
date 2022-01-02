#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
    ListNode *temp;

    bool check(ListNode *p)
    {
        if (p == NULL)
            return true;

        bool isPal = check(p->next) & (p->val == temp->val);
        temp = temp->next;

        return isPal;
    }
    bool isPalindrome(ListNode *head)
    {

        if (!head || !head->next)
            return true;

        temp = head;

        return check(head);
    }
};


// Another aproach

/*
Traverse to the mid of the link list using fast and slow ptr technique and then reverse the link list from the mid.
and then compare the 2 halves.
*/