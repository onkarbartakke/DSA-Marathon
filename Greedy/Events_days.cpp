#include <bits/stdc++.h>

using namespace std;
/*
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.


You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.
*/
class Solution
{
    public:
    int maxEvents(vector<vector<int>> &events)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        sort(events.begin(), events.end());
        int i = 0;
        int count = 0;
        int n = events.size();
        for (int d = 1; d <= 100000; d++)
        {
            while (!pq.empty() && pq.top() < d)
                pq.pop();

            while (i < n && d == events[i][0])
                pq.push(events[i++][1]);

            if (pq.size())
            {
                pq.pop();
                count++;
            }
            if (pq.empty() && i >= n)
                break;
        }

        return count;
    }
};

/*
Each event is described as events[i] = [startDayi, endDayi].
On any day we can attend only one event.
So on each day d we have to choose an optimal event among events that are going on that day i.e. amongst all events such that 
{startTimei <= d <= endTimei}
So on any day out of all events that are going on we choose the event that is going to end soon because for other events that 
are going on ,we might get a chance to visit them later( but not always, in case we do not get the chance to visit other events 
we will anyway lose one event).
For keeping track of ending times of ongoing events we use a priority queue.
If there are no meetings going on a particular day, we don't attend any meeting.


https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/1304132/Priority-Queue_Step-by-Step-explanation
*/