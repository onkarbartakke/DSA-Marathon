#include <bits/stdc++.h>

using namespace std;
/*
Given a string consisting of some numbers, not separated by any separator. 
The numbers are positive integers and the sequence increases by one at each number except the missing number. 
The task is to complete the function missingNumber which return's the missing number. The numbers will have no more than six digits. 
Print -1 if input sequence is not valid
*/

// { Driver Code Starts

const int MAX_DIGITS = 5;

int missingNumber(const string &str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << missingNumber(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

/* You are required to complete this function
which return the required missing number
if present else return -1*/

long long sto(string s)
{
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
        x = x * 10 + s[i] - '0';
    return x;
}
int missingNumber(const string &str)
{
    // Code here

    for (int l = 1; l <= 6; l++)
    {
        string s = str.substr(0, l);

        long long prev = sto(s);

        int j = l;
        int c = 0;
        string temp = "";
        bool flag = false;
        int num;
        while (j < str.size())
        {
            temp += str[j];
            j++;

            //cout<<"\n"<<temp<<" ";
            long long n = sto(temp);
            // cout<<n<<" ";
            if (prev + 1 == n)
            {
                prev = n;
                temp = "";
            }
            else if (prev + 2 == n)
            {
                c++;
                num = prev + 1;
                prev = n;
                temp = "";
            }
            else if (prev < n)
            {
                flag = true;
            }
        }

        if (c == 1 && flag == false)
            return num;
    }

    return -1;
}