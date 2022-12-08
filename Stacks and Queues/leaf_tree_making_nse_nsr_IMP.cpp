#include <bits/stdc++.h>

using namespace std;
/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree,
 respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. 
It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.
*/
class Solution
{
public:
    int mctFromLeafValues(vector<int> &a)
    {

        int n = a.size();

        stack<int> st;

        st.push(INT_MAX);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() <= a[i])
            {
                int minEle = st.top();
                st.pop();

                res += (minEle * (min(st.top(), a[i])));
            }

            st.push(a[i]);
        }

        while (st.size() > 2)
        {
            int minEle = st.top();
            st.pop();

            res += (minEle * st.top());
        }

        return res;
    }
};

/*
Intuition
Let's review the problem again.

When we build a node in the tree, we compared the two numbers a and b.
In this process,
the smaller one is removed and we won't use it anymore,
and the bigger one actually stays.

The problem can translated as following:
Given an array A, choose two neighbors in the array a and b,
we can remove the smaller one min(a,b) and the cost is a * b.
What is the minimum cost to remove the whole array until only one left?

To remove a number a, it needs a cost a * b, where b >= a.
So a has to be removed by a bigger number.
We want minimize this cost, so we need to minimize b.

b has two candidates, the first bigger number on the left,
the first bigger number on the right.

The cost to remove a is a * min(left, right).


Solution 1
With the intuition above in mind,
the explanation is short to go.

We remove the element form the smallest to bigger.
We check the min(left, right),
For each element a, cost = min(left, right) * a

Time O(N^2)
Space O(N)

Python

    def mctFromLeafValues(self, A):
        res = 0
        while len(A) > 1:
            i = A.index(min(A))
            res += min(A[i - 1:i] + A[i + 1:i + 2]) * A.pop(i)
        return res

Solution 2: Stack Soluton
we decompose a hard problem into reasonable easy one:
Just find the next greater element in the array, on the left and one right.
Refer to the problem 503. Next Greater Element II


Time O(N) for one pass
Space O(N) for stack in the worst cases


Java:

    public int mctFromLeafValues(int[] A) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(Integer.MAX_VALUE);
        for (int a : A) {
            while (stack.peek() <= a) {
                int mid = stack.pop();
                res += mid * Math.min(stack.peek(), a);
            }
            stack.push(a);
        }
        while (stack.size() > 2) {
            res += stack.pop() * stack.peek();
        }
        return res;
    }
    */