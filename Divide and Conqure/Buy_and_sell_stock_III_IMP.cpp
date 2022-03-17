#include <bits/stdc++.h>

using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
*/
class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        int Lmin, Rmax;

        vector<int> left(n);
        vector<int> right(n);

        left[0] = 0;
        right[n - 1] = 0;

        Lmin = prices[0];
        Rmax = prices[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], prices[i] - Lmin);
            Lmin = min(Lmin, prices[i]);

            right[n - 1 - i] = max(right[n - i], Rmax - prices[n - 1 - i]);
            Rmax = max(Rmax, prices[n - 1 - i]);
        }

        int profit = right[0];

        // for(int i = 0 ; i < n ; i++)
        // {
        //     cout<<left[i]<<" ";
        // }
        // cout<<"\n\n";
        // for(int i = 0 ; i < n ; i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        for (int i = 1; i < n; i++)
        {

            profit = max(profit, left[i - 1] + right[i]);
        }

        return profit;
    }
};

// Better Approach
/*
var maxProfit = function(prices) {
  let oneBuyOneSell = 0;
  let twoBuyTwoSell = 0;
  let oneBuy = Number.POSITIVE_INFINITY
  let twoBuy = Number.POSITIVE_INFINITY;
  
  for(let i = 0; i < prices.length; i++) {
    const p = prices[i];
    oneBuy = Math.min(oneBuy, p);
    oneBuyOneSell = Math.max(oneBuyOneSell, p - oneBuy);
    twoBuy = Math.min(twoBuy, p - oneBuyOneSell);
    twoBuyTwoSell = Math.max(twoBuyTwoSell, p - twoBuy);
  }
  
  return twoBuyTwoSell;
};
Similar to Buy and Sell Stock I, where only one transaction allowed, we keep track the lowest price and once the price exceeds t
he old lowest price, we record the difference.

var maxProfit = function(prices) {
  const size = prices.length;
  let lowPrice = prices[0];
  let profit = 0;
  
  for(let i = 1; i < size; i++) {
    if(prices[i] < lowPrice) {
      lowPrice = prices[i];
    } else {
      profit = Math.max(prices[i] - lowPrice, profit);
    }
  }
  
  return profit;
};
Here, the oneBuy keeps track of the lowest price, and oneBuyOneSell keeps track of the biggest profit we could get.
Then the tricky part comes, how to handle the twoBuy? Suppose in real life, you have bought and sold a stock and made $100 dollar profit. 
When you want to purchase a stock which costs you $300 dollars, how would you think this? You must think, um, I have made $100 profit, 
so I think this $300 dollar stock is worth $200 FOR ME since I have hold $100 for free.
There we go, you got the idea how we calculate twoBuy!! We just minimize the cost again!! The twoBuyTwoSell is just making as 
much profit as possible.
Hope this explanation helps other people to understand this!*/