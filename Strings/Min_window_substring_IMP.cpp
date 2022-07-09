#include <bits/stdc++.h>

using namespace std;
/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window.
 If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.


 */
class Solution
{
public:
    string minWindow(string s, string t)
    {

        vector<int> cnt(128, 0);

        for (int i = 0; i < t.size(); i++)
            cnt[t[i]]++;

        int required = t.size();

        int i = 0, left = 0, start = 0, len = INT_MAX;

        while (i <= s.size() && start < s.size())
        {
            if (required > 0)
            {
                if (i == s.size())
                    break;

                cnt[s[i]]--;

                if (cnt[s[i]] >= 0)
                    required--;

                i++;
            }
            else if (required == 0)
            {
                if (len > i - start)
                {
                    len = i - start;
                    left = start;
                }

                cnt[s[start]]++;

                if (cnt[s[start]] > 0)
                    required++;

                start++;
            }
        }

        if (len == INT_MAX)
            return "";
        else
            return s.substr(left, len);
    }
};

// https://leetcode.com/problems/minimum-window-substring/discuss/26917/16ms-simple-and-neat-c%2B%2B-solution-only-using-a-vector.-Detailed-explanation

/*
I will first give the solution then show you the magic template.

The code of solving this problem is below. It might be the shortest among all solutions provided in Discuss.

string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
Here comes the template.

For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions. A general way is to use a hashmap assisted with two pointers. The template is given below.

int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }
        /*
        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }
    /*
            while(/* counter condition */)
{

    /* update d here if finding minimum*/

// increase begin to make it invalid/valid again
                /*
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
}

/* update d here if finding maximum*/ /*
}
return d;
}
One thing needs to be mentioned is that when asked to find maximum substring, we should update maximum after the inner while loop to guarantee that the substring is valid. On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.

The code of solving Longest Substring with At Most Two Distinct Characters is below:

int lengthOfLongestSubstringTwoDistinct(string s) {
vector<int> map(128, 0);
int counter=0, begin=0, end=0, d=0;
while(end<s.size()){
if(map[s[end++]]++==0) counter++;
while(counter>2) if(map[s[begin++]]--==1) counter--;
d=max(d, end-begin);
}
return d;
}
The code of solving Longest Substring Without Repeating Characters is below:

Update 01.04.2016, thanks @weiyi3 for advise.

int lengthOfLongestSubstring(string s) {
vector<int> map(128,0);
int counter=0, begin=0, end=0, d=0;
while(end<s.size()){
if(map[s[end++]]++>0) counter++;
while(counter>0) if(map[s[begin++]]-->1) counter--;
d=max(d, end-begin); //while valid, update d
}
return d;
}


*/