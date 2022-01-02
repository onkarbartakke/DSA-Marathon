#include <bits/stdc++.h>

using namespace std;
/*
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

 */
class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {

        int r, len;
        len = 1;
        r = 0;
        for (len = 1; len <= k; len++)
        {
            r = (10 * r + 1) % k;
            if (r == 0)
                return len;
        }

        return -1;
    }
};

/*
Now the question arises that we can add a 0 easily at the end to increase the number of digits but how to add a specific digit at end 
(in our case instead of 0's we need 1's) !???
Okkk , so let's take the same number 123 . let's say this time we want to append a digit 2 instead of 0 .
An observation we all know:-If we are appending a single digit to a number it increases the value of the last digit of the original number
 by the same amount
123[N] +2[single digit] = 125 [final number]
so we can see that in N we addded a digit 2 and the final number is incremented by 2

4th Intuition:-

Now let's see how can we conclude the answer for how to append a specific digit at end (in our case instead of 0's we need 1's) !???
So in conclusion, to append a specific digit at the end of a number, we first multiply it by 10 (freeing up the last digit slot) and 
then add the digit that we want to append.
Let's take a example:-

Let's say we want to append 2 at the end of 123

n*10 = 1230(slot freed)
n*10 + 2 = 1232 (Number 2 appended).
Not gonna lie that was cool :)
Final Intution:-

After understanding the above 4 intuitons we've understood now how to append a digit at the end of a number. Let us see how can we
 generate the sequence 1, 11, 111, ....111...11 using the above Intuitions.
So now we need to append 1's as we increment our sequence

So, Let's start out with num = 1 and repeatedly do num = num * 10 + 1, then in every iteration we'll get a new number with a digit 
1 appended and in the end we will get the above sequence.

1 * 10 + 1 = 11
11 * 10 + 1 = 111
111 * 10 + 1 = 1111
1111 * 10 + 1 = 11111
11111 * 10 + 1 = 111111
1111111 * 10 +1 =1111111

The rise of a new issue :(

We can get the remainder directly from N by N % K and move on to the next N by N = N * 10 + 1.
But but there is a issue when N will soon be overflow since max integer in cpp/java is +2,147,483,647, which means 
the max N is 1,111,111,111 .
So instead of creating whole new numbers every time we will just use the remainder of the next N with the previous reminder
So how do we do it ????
By the rules of modular arithmetic (a * b + c) mod m is same as ((a * b) % m + c % m) % m.THINK!!!

Let's see the proof of the above statement:-

Here is a rule to get the remainder of the next N with the previous remainder.
N = m * k + r ......*where r is n % k and m is modulo*
10 * N + 1 = 10 * (m * k + r) + 1
10 * N+ 1 = 10 * m * k + 10 * r + 1
(10 * N + 1) % k = (10 * m * k + 10 * r + 1) % k
(10 * N + 1) % k = (10 * r + 1) % k // (10 * m * k) % k = 0
So whatever N is, (10 * n + 1) % k equals to (10 * r + 1) % k, where r is n % k. So that's why we only need to keep the 
remainder and thus the issue get's resolved .

*/