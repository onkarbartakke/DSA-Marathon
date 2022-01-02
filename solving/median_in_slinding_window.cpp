#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int getMedian(vector<int> &count, int d, vector<int> &expenditure)
{
    int a = 0, b = 0;

    vector<int> cumm_count(count);

    cumm_count[0] = count[0];

    for (int i = 1; i < 201; i++)
    {
        cumm_count[i] += cumm_count[i - 1];
    }

    if (d % 2 == 0)
    {
        int i = 0;
        int first, second;
        first = d / 2;
        second = d / 2 + 1;

        for (i = 0; i < 201; i++)
        {
            if (first <= cumm_count[i])
            {
                a = i;
                break;
            }
        }

        for (; i < 201; i++)
        {
            if (second <= cumm_count[i])
            {
                b = i;
                break;
            }
        }

        return a + b;
    }
    else
    {
        int first = d / 2 + 1;

        for (int i = 0; i < 201; i++)
        {
            if (first <= cumm_count[i])
            {
                a = 2 * i;
                return (2 * i);
            }
        }
    }

    return a + b;
}
int activityNotifications(vector<int> expenditure, int d)
{

    vector<int> count(201, 0);

    int i, j, n;
    n = expenditure.size();
    int ct = 0;
    for (i = 0; i < d; i++)
    {
        count[expenditure[i]]++;
    }

    for (i = d; i < n; i++)
    {
        int med = getMedian(count, d, expenditure);

        if (expenditure[i] >= med)
            ct++;

        count[expenditure[i]]++;
        count[expenditure[i - d]]--;
    }

    return ct;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++)
    {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
