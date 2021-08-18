#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        int i, j, k, depth = 0, lsize;
        bool present = false;

        set<string> myset;

        for (i = 0; i < wordList.size(); i++)
        {
            if (endWord.compare(wordList[i]) == 0)
                present = true;

            myset.insert(wordList[i]);
        }

        if (present == false)
            return 0;

        queue<string> qu;

        qu.push(beginWord);

        while (!qu.empty())
        {
            lsize = qu.size();
            depth++;

            while (lsize--)
            {
                string s = qu.front();
                qu.pop();

                for (i = 0; i < s.length(); i++)
                {
                    string temp = s;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;

                        if (temp.compare(s) == 0)
                            continue;

                        if (temp.compare(endWord) == 0)
                            return depth + 1;

                        if (myset.find(temp) != myset.end())
                        {
                            qu.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};

int main()
{
}