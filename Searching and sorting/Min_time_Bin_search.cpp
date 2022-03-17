#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long TripCounter(vector<int> &time, long long givenTime)
    {
        long long trips = 0;
        for (auto it : time)
        {
            long long val = it;

            trips += (givenTime / val);
        }

        return trips;
    }
    long long minimumTime(vector<int> &time, int totalTrips)
    {

        long long low = 0, high = 1e14, mid, ans;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            long long possibleTrips = TripCounter(time, mid);

            if (possibleTrips >= totalTrips)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

/*
You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
Return the minimum time required for all buses to complete at least totalTrips trips.
*/