#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

#include <bits/stdc++.h>

vector<int> gapWeights(int n, vector<vector<int>> gaps, int o, vector<int> queries)
{
    // Write your code here.

    vector<pair<int, int>> qurs;

    for (int i = 0; i < queries.size(); i++)
    {
        qurs.push_back({queries[i], i});
    }

    sort(qurs.begin(), qurs.end());

    sort(gaps.begin(), gaps.end());

    multiset<pair<int, int>, greater<pair<int, int>>> mt;

    int i = 0;
    vector<int> ans(queries.size(), 0);

    for (auto q : qurs)
    {
        int ele = q.first;
        int ind = q.second;

        while (i < n && ele >= gaps[i][0])
        {
            mt.insert({gaps[i][2], gaps[i][1]});
            i++;
        }

        while (!mt.empty() && ele > (*mt.begin()).second)
        {
            mt.erase(mt.begin());
        }

        if (!mt.empty())
        {
            int val = (*mt.begin()).first;
            ans[ind] = val;
        }
        else
            ans[ind] = 0;
    }

    return ans;
}
int main()
{
    int t;
    cin >> t;
}

/*
Ninja has a vector of ‘N’ elements called as 'GAP' where 'GAP[i]' = [left(i), right(i), W(i)] which describes the ith gap 
starting at left(i) and ending at right(i) {both are inclusive} and having weight W(i) for all integers in the range.
Now, Alex enters the room and asks Ninja 'Q queries’ where he has to say the maximum possible weight of each integer,
 and if no gaps include it, Ninja can say 0. As Ninja is weak in calculating such stuff, he assigns this task to you.
Your task is to print the answer to 'Q' queries which Alex asks Ninja, where each query is to be answered with the maximum 
weight that integer can hold. It is told that each integer can hold only a single gap’s weight.
EXAMPLE:
Input: ‘GAP’ = [[1, 5, 2], [4, 7, 9], [9, 14, 6], [8, 15, 3]] and ‘QUERIES’ = [3, 5, 8, 14]
Output: [2, 9, 3, 6]
Explanation:
For query = 3, the gap [1, 5, 2] only includes 3. The answer to the query is the Weight of ‘GAP[1]’, which is 2.
For query = 5, the gap [1, 5, 2] and [4, 7, 9] include 5. Thus, the answer to the query is 9.
For query = 8, the gap [8,15,3] contains 8. Thus, the answer to the query is 3.
For query = 14, the gap [9, 14, 6] and [8, 15, 3] include 14. Thus, the answer to the query is 6.
Input Format :
The first line of input contains an integer ‘T’, denoting the number of test cases.

The first line of each test case contains two integers, ‘N’ and ‘Q’, denoting the array’s length‘ GAP’ and the total number of queries that are asked.

The following ‘N’ line contains three integers denoting the ‘left’, ‘right’ and ‘W’ of the i’th gap.

The next line contains ‘Q’ space-separated integers denoting the elements of the array ‘QUERIES’.
Output Format :
For each test case, print ‘Q’ integers denoting the maximum weight that the integer can hold. If no gaps contain integer ‘i’, then print 0.

Print the output of each test case in a new line.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10^5
1 <= ‘Q’ <= 10^3
1 <= ‘GAP[i][0]’ <= ‘GAP[i][1]’ <= 10^5
1 <= ‘GAP[i][2]’ <= 10^9, where ‘GAP[i][2]’ is ‘W[i]’
1 <= ‘QUERIES[i]’ <= 10^5
Time Limit : 1 sec
*/