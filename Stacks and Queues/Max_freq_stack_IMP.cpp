#include <bits/stdc++.h>

using namespace std;
/*
Design a stack-like data structure to push elements to the stack and pop the most 
frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
*/
class FreqStack
{
    public:
    unordered_map<int, int> freq;

    unordered_map<int, stack<int>> fst;  // Frequency stack

    int maxFreq = 0;
    FreqStack()
    {
    }

    void push(int val)
    {

        maxFreq = max(maxFreq, ++freq[val]);

        fst[freq[val]].push(val);
    }

    int pop()
    {

        int x = fst[maxFreq].top();
        fst[maxFreq].pop();

        if (fst[maxFreq].empty())
        {
            maxFreq--;
        }

        freq[x]--;

        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */