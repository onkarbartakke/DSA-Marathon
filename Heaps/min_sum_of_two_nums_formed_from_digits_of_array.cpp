#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string solve(int a[], int n)
{
    // code here

    sort(a, a + n);

    int i, j;

    string s = "";

    i = n - 1;
    j = n - 2;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        if (a[i] == 0 && a[j] == 0 && carry == 0)
        {
            i = i - 2;
            j = j - 2;
        }
        else
        {
            int p = a[i] + a[j] + carry;

            int val = (p % 10);

            char c = (48 + val);

            s = c + s;

            carry = (p / 10);

            i = i - 2;
            j = j - 2;
        }
    }

    if (i < 0 && j < 0)
    {
        if (carry == 0)
            return s;
        else
        {
            char c = (48 + carry);
            s = c + s;
            return s;
        }
    }
    else
    {
        int p = a[i] + carry;
        if (p == 0)
            return s;

        int val = (p % 10);
        char c = (48 + val);
        s = c + s;

        carry = p / 10;
        if (carry == 0)
            return s;
        else
        {
            c = (48 + carry);
            s = c + s;
            return s;
        }
    }
}

int main()
{
}