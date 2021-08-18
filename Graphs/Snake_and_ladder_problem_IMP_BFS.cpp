#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int minThrow(int N, int arr[])
{
    // code here
    int i, j, k, move = 0;

    map<int, int> snklad;

    for (i = 0; i < N; i++)
    {
        int u = arr[2 * i];
        int v = arr[2 * i + 1];

        snklad[u] = v;
    }

    queue<int> qu;
    bool found = false;

    vector<bool> visited(31, false);

    qu.push(1);
    visited[1] = true;

    while (!qu.empty() && !found)
    {
        int sz = qu.size();

        while (sz--)
        {
            int t = qu.front();
            qu.pop();

            for (int die = 1; die <= 6; die++)
            {
                int curr = t + die;

                if (curr == 30)
                {
                    found = true;
                    break;
                }

                if (curr <= 30 && snklad[curr] && !visited[snklad[curr]])
                {
                    if (snklad[curr] == 30)
                    {
                        found = true;
                        break;
                    }

                    visited[snklad[curr]] = true;
                    qu.push(snklad[curr]);
                }
                else if (curr <= 30 && !snklad[curr] && !visited[curr])
                {
                    if (curr == 30)
                    {
                        found = true;
                        break;
                    }

                    visited[curr] = true;
                    qu.push(curr);
                }
            }
        }

        move++;

        if (found)
            break;
    }

    return move;
}

int main()
{
    
}