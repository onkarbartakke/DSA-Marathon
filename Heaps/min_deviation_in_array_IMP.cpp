#include <bits/stdc++.h>

using namespace std;
/*
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.
*/
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {

        priority_queue<int, vector<int>> maxheap;

        int min_ele = INT_MAX;
        for (auto it : nums)
        {
            if (it % 2 == 1)
            {
                it = it * 2;
            }

            min_ele = min(min_ele, it);
            maxheap.push(it);
        }

        int res = INT_MAX;
        while (maxheap.top() % 2 == 0)
        {
            int n = maxheap.top();
            res = min(res, n - min_ele);
            min_ele = min(min_ele, n / 2);
            maxheap.push(n / 2);
            maxheap.pop();
        }

        return min(res, maxheap.top() - min_ele);
    }
};

/*
We have two types of operations: double odd numbers, and halve even numbers. We can try to sort all numbers, and increase the 
smallest number (if it's odd) and decrease the largest number (if it's even). This can get quite complicated.

Intuition 1: we can divide even numbers multiple times - till we get an odd number, but we can only double odd numbers once. 
After that, it will become an even number.

Intuition 2: Even numbers never increase.

Flip: we can double all odd numbers first, so we can get forget of the second operation. Now, we only need to decrease the 
largest number - while it's even, which results a very simple solution.

Solution
Double odd numbers and put all numbers into a max heap. Track the smallest number. Track the minimum difference between 
the top of the heap and the smallest number. While the top of the heap is even, remove it, divide, and put back to the heap.

Two solutions below use the same approach; the first one is easier to read, and the second one - faster 
(since we use the array version of max heap).
*/

int main()
{
    int n,i;
    cin>>n;

    vector<int>a(n);

    for(int i  = 0 ; i <n ;i++)
    {
        cin>>a[i];
    }

    
}