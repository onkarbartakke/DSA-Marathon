#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumWaitingTime(vector<int> queries)
{
    // Write your code here.i
    sort(queries.begin(), queries.end());

    int n = queries.size();

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += (queries[i]);
        ans += sum;
    }

    return ans;
}

int main()
{

    
}
