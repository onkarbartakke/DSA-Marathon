#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:
        static bool cmp(vector<int> a, vector<int> b)
        {
            return a[1] < b[1];
        }

        int scheduleCourse(vector<vector<int>> &courses)
        {

            int n = courses.size();
            int time = 0;
            priority_queue<int> q;

            sort(courses.begin(), courses.end(), cmp);

            for (int i = 0; i < n; i++)
            {
                if (time + courses[i][0] <= courses[i][1])
                {
                    // we can take this course
                    time += courses[i][0];
                    q.push(courses[i][0]);
                }
                else
                {
                    if (!q.empty() && q.top() > courses[i][0])
                    {
                        // current course is actually of
                        //less duration and can be taken
                        int x = q.top();
                        q.pop();
                        time -= x;
                        time += courses[i][0];
                        q.push(courses[i][0]);
                    }
                }
            }

            return q.size();
        }
};