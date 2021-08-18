#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

static bool mycomp(Job a, Job b)
{
    return (a.profit > b.profit);
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    //int time=0;
    int count = 0;
    int profit = 0;

    sort(arr, arr + n, mycomp);

    vector<int> slots(n + 2, -1);

    for (int i = 0; i < n; i++)
    {
        int d = arr[i].dead;

        if (slots[d] == -1)
        {
            slots[d] = arr[i].id;
            count++;
            profit += (arr[i].profit);
        }
        else
        {
            while (d > 1 && slots[d] != -1)
            {
                d--;
            }

            if (slots[d] == -1)
            {
                slots[d] = arr[i].id;
                count++;
                profit += (arr[i].profit);
            }
        }
    }

    vector<int> ans(2);
    ans[0] = count;
    ans[1] = profit;

    return ans;
}

int main()
{
}