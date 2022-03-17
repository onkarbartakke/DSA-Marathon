#include <bits/stdc++.h>

using namespace std;
/*
Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. 
If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
*/


//Hash Map approach
class WordFilter1
{
public:
private:
    unordered_map<string, int> hashMap;

public:
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++)
            {
                string p = word.substr(0, j);
                for (int k = 0; k < wordSize; k++)
                {
                    string s = word.substr(k, wordSize);
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        string s = prefix + "|" + suffix;
        return hashMap[s] - 1;
    }
};
int main()
{
}