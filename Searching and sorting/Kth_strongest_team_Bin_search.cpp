#include <bits/stdc++.h>

using namespace std;



int GreaterTeams(vector<int> &arr, int n, int mid)
{
    int count = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        while (j > i && arr[i] + arr[j] < mid)
            j--;

        if (j > i)
            count += (j - i);
    }

    return count;
}

int KthStrong(int n, int k, vector<int> arr)
{

    // Write your code here.
    sort(arr.begin(), arr.end(), greater<int>());

    int high = arr[0] + arr[1];
    int low = arr[n - 1] + arr[n - 2];
    int ans;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int rank = GreaterTeams(arr, n, mid);

        if (rank >= k)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

/*
Ninja village hosts a coding contest every year. 
Coders all over the village participate in the contest to win the grand prize.
There are total ‘N’ coders in the village with each coder having skill represented by an array of 
integers of size ‘N’, coders form a team of two to participate in the contest, and the strength 
of the team is the sum of skill of both coders in the team.
You are given an integer ‘N’ representing the number of coders in the 
village and an array ‘ARR’ of size ‘N’ where ‘ARR[i]’ (‘0’ <= ‘i’ <= ‘N-1’) 
represents the skill of ‘ith’ coder.
You are also given an integer ‘K’. Your task is to find the strength of “Kth” strongest team out of all ‘(N*(N-1))/2’ 
possible teams.
*/