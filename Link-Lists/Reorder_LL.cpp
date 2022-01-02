#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * 
 * input
 *  1 2 3 4 5 
 * 
 * output
 * 1 5 2 4 3
 */
class Solution {
    public:
    void reorderList(ListNode* head) {
     
        ListNode *p1,*p2;
        p1=head;
        p2=head;
        
        while(p2 && p2->next)
        {
            p1=p1->next;
            p2=p2->next->next;
        }
        
        ListNode *h = p1->next;
        p1->next=NULL;
        
        stack<int>st;
        
        while(h)
        {
            st.push(h->val);
            h = h->next;
        }
        
        p1=head;
        
        while(!st.empty())
        {
            ListNode *t = new ListNode;
            
            t->val = st.top();
            st.pop();
            
            t->next = p1->next;
            p1->next=t;
            
            p1 = t->next;
        }
        
       
    }
};