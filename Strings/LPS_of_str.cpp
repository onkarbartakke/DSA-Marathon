#include <bits/stdc++.h>

using namespace std;

void FindLPS(string s)
{
    cout << s << "\n\n";

    int n = s.length();

    vector<int> lps(n, 0);

    int j;
    for (int i = 1; i < n; i++)
    {
        j = lps[i - 1];

        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];

        if (s[i] == s[j])
            j++;

        lps[i] = j;
    }

    for(int i = 0 ; i < n ; i++)
    cout<<lps[i]<<" ";
}
int main()
{
    string s;
    cin >> s;

    FindLPS(s);
}