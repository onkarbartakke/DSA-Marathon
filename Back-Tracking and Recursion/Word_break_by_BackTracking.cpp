#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
bool contains(vector<string> &dict, string s, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (dict[i] == s)
            return true;
    }

    return false;
}

void wordBreakUntil(string s, int size, vector<string> &dict, string res, int n)
{
    int i, j;
    for (i = 1; i <= size; i++)
    {
        string prefix = s.substr(0, i);

        if (contains(dict, prefix, n))
        {
            if (i == size)
            {
                res = res + prefix;

                ans.push_back(res);
                return;
            }

            wordBreakUntil(s.substr(i, size - i), size - i, dict, res + prefix + " ", n);
        }
    }
}
vector<string> wordBreak(int n, vector<string> &dict, string s)
{
    // code here

    string res = "";

    wordBreakUntil(s, s.size(), dict, res, n);

    return ans;
}

int main()
{
}