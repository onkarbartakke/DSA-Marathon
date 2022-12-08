#include<bits/stdc++.h>

using namespace std;

/*
Given an string A. The only operation allowed is to insert  characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.

*/

int solve(string A) {

    string B = A;
    reverse(B.begin(),B.end());

    string pal = A+"#"+B;

    int n,i,j,m;

    m = pal.length();
    n = A.length();

    vector<int>lps(m,0);

    for(i=1;i<m;i++)
    {
        j = lps[i-1];


        while(j>0 && pal[i]!=pal[j])
        j = lps[j-1];


        if(pal[i] == pal[j])
        j++;

        lps[i] = j;
    }

    cout<<pal<<"\n\n";

    for(auto it : lps)
    cout<<it<<" ";
    return n - lps[m-1];
}

int main()
{
    string A;
    cin>>A;

    cout<<"\n"<<solve(A);
}