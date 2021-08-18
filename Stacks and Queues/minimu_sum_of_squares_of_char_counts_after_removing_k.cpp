#include<iostream>
#include<queue>

using namespace std;

int minValue(string s, int k)
{
    // code here
    int i, l;
    l = s.length();
    if (k >= l)
        return 0;

    priority_queue<int> qu;

    int hash[26] = {0};

    for (i = 0; i < l; i++)
        hash[s[i] - 'a']++;

    for (i = 0; i < 26; i++)
    {
        if (hash[i] > 0)
        {
            qu.push(hash[i]);
        }
    }
    int temp;
    while (k--)
    {
        temp = qu.top();
        qu.pop();
        temp--;
        qu.push(temp);
    }
    int ans = 0;
    while (!qu.empty())
    {
        temp = qu.top();
        ans = ans + (temp * temp);
        qu.pop();
    }

    return ans;
}

int main()
{
    
}