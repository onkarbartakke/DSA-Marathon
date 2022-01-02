#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s)
{

    vector<pair<char, int>> v;
    char c = '\0';
    int i = -1;
    for (auto it : s)
    {
        if (it == c)
        {
            v[i].second++;
        }
        else
        {
            c = it;
            i++;
            v.push_back({it, 1});
        }
    }

    long count = 0;

    count = v[0].second * (v[0].second + 1) / 2;

    for (i = 1; i < v.size(); i++)
    {
        count += (v[i].second * (v[i].second + 1)) / 2;

        if (i + 1 < v.size() && v[i - 1].first == v[i + 1].first && v[i].second == 1)
            count += (min(v[i - 1].second, v[i + 1].second));
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
