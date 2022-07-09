#include<bits/stdc++.h.>

using namespace std;

int MaxPartitions(string s)
{
    int n = s.length();
    unordered_map<char,int>mp;

    for(int i = 0 ; i < n ; i++)
    {
        mp[s[i]] = i;
    }

    int count = 0, last_pos = mp[s[0]], cur_len = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(i<=last_pos)
        {
            int curr_last_pos = mp[s[i]];
            cur_len++;
            last_pos = max(last_pos , curr_last_pos);
        }
        else
        {
            count++;
            cur_len = 1;
            last_pos = mp[s[i]];
        }
    }

    if(cur_len>0)
    count++;

    return count;
}
int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    cout<<"\n\nMax partitions without repeating char are : "<<MaxPartitions(s);
}

/*
Maximize partitions such that no two substrings have any common character

Given string str of size N, the task is to print the number of substrings formed after maximum possible partitions such that no two substrings have a common character.
Examples: 

Input : str = “ababcbacadefegdehijhklij” 
Output : 3 
Explanation: 
Partitioning at the index 8 and at 15 produces three substrings “ababcbaca”, “defegde” and “hijhklij” 
such that none of them have a common character. So, the maximum partitions is 3.
Input: str = “aaa” 
Output: 1 
Explanation: 
Since, the string consists of a single character, no partition can be performed. 
 

Recommended: Please try your approach on {IDE} first, before moving on to the solution.
Approach:

Find the last index of every unique character from the end of the string and store it in a map.
Traverse the array from the index 0 up to the last index and make a separate variable to store the ending index of partition.
Traverse for every variable in the string and check if the end of the partition, denoted by the index of str[i] stored in the map, is greater than the previous end. If so, update it.
Check if the current variable exceeds the end of the partition. It means the first partition is found. Update the end of the partition to max(k, mp[str[i]]).
Traverse the whole string and use a similar process to find the next partition and so on.

*/