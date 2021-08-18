#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// CPP program to find maximum number of stocks that
// can be bought with given constraints.


/*
So, we will sort the pair of two values i.e { stock price, day } according to the stock price, and if stock prices are same, 
then we sort according to the day.
Now, we will traverse along the sorted list of pairs, and start buying as follows:
Let say, we have R rs remaining till now, and the cost of product on this day be C, and we can buy atmost L products on this day then,
total purchase on this day (P) = min(L, R/C)
Now, add this value to the answer.

total_purchase = total_purchase + P, where P =min(L, R/C)
Now, subtract the cost of buying P items from remaining money, R = R – P*C.
Total number of products that we can buy is equal to total_purchase.

*/

// Return the maximum stocks
int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> v;

    // Making pair of product cost and number
    // of day..
    for (int i = 0; i < n; ++i)
        v.push_back(make_pair(price[i], i + 1));

    // Sorting the vector pair.
    sort(v.begin(), v.end());

    // Calculating the maximum number of stock
    // count.
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += min(v[i].second, k / v[i].first);
        k -= v[i].first * min(v[i].second,
                              (k / v[i].first));
    }

    return ans;
}

// Driven Program
int main()
{
    int price[] = {10, 7, 19};
    int n = sizeof(price) / sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;

    return 0;
}
