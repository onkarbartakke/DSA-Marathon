#include <bits/stdc++.h>

using namespace std;
/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {

        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += max(left[i], right[i]);
        }

        return count;
    }
};
/*
o use two variables 'up' and 'down' to count the steps of continuous up and down respectively, and a 'peak' representing
the peak before going down. In the below example:

[0, 1, 20, 9, 8, 7]
Scan from left to right, first child is given 1 candy;
the second child is given 2 candies, and up=1;
the third child is given 3 candies, and up=2; peak=2;
the fourth child is given 1 candy, and down=1; and third child still has 3 candies since peak=2;
the fifth child is given 1 candy, and down=2; and the previous child needs 1 more candy now but the third child no need more;
the sixth child is given 1 candy, and down=3; and both the fifth and fourth child needs 1 more candy now, and the peak,
the third child need 1 more as well.

        public int Candy(int[] ratings) {
            if (ratings.Length == 0) return 0;
            int ret = 1;
            int up = 0, down = 0, peak = 0;
            for (int i = 1; i < ratings.Length; i++) {
                if (ratings[i - 1] < ratings[i]) {
                    peak = ++up;
                    down = 0;
                    ret += 1 + up;
                } else if (ratings[i - 1] == ratings[i])  {
                    peak = up = down = 0;
                    ret += 1;
                } else {
                    up = 0;
                    down++;
                    ret += 1 + down + (peak >= down ? -1 : 0);
                }
            }

            return ret;
        }
Comments: 20
BestMost VotesNewest to OldestOldest to Newest
Type comment here... (Markdown is supported)

Preview

Post
JobQ's avatar
JobQ
1440
January 6, 2019 10:28 AM

Read More
add some explain about peak >= down ? -1:0



when peak >= down, the candy for the peak still don't need to change.

For example, [0, 1, 20, 9, 8, 7], for the first 5 number, we need to assign [1,2,3,2,1] candies.
But when 7 comes up, we need to raise the value of the peak, which is 3 above, it need to be 4, [1,2,4,3,2,1]
This solution here, make it to be [1,2,3,1,2,4], the sum are same. Really brilliant.
*/