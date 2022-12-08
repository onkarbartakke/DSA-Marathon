#include <bits/stdc++.h>

using namespace std;
/*
There are n different online courses numbered from 1 to n. 
You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course 
should be taken continuously for durationi days and must be finished before or on lastDayi.
You will start on the 1st day and you cannot take two or more courses simultaneously.
Return the maximum number of courses that you can take.*/


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