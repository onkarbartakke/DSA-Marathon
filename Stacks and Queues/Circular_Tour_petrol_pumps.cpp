#include <iostream>
#include <queue>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    //Your code here
    int balance, start, i, j;

    for (i = 0; i < n; i++)
    {
        balance = p[i].petrol - p[i].distance;
        if (balance >= 0)
        {
            start = i;
            break;
        }
    }
    balance = 0;

    for (i = start; i < n;)
    {
        balance += p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            i++;
            for (; i < n; i++)
            {
                balance = p[i].petrol - p[i].distance;
                if (balance >= 0)
                {
                    start = i;
                    balance = 0;
                    break;
                }
            }
        }
        else
        {
            i++;
        }
    }

    if (balance < 0)
        return -1;

    for (j = 0; j < start; j++)
    {
        balance += p[j].petrol - p[j].distance;

        if (balance < 0)
            return -1;
    }

    return start;
}

int main()
{
}