#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isPalindrome(string s, int low, int high)
{
    while(low<high)
    {
        if(s[low]!=s[high])
        return false;

        low++;
        high--;
    }

    return true;
}

void Find_all_pali_partitions_until(vector<vector<string>>&All_parts, vector<string>&curr_part, int start, int n, string s)
{
    if(start>=n)
    {
        All_parts.push_back(curr_part);
        return;
    }

    int i;
    for(i=start;i<n;i++)
    {
        if(isPalindrome(s,start,i))
        {
            curr_part.push_back(s.substr(start,i-start+1));

            Find_all_pali_partitions_until(All_parts,curr_part,i+1,n,s);

            curr_part.pop_back();
        }
    }
}

void Find_all_palindromic_partitions(string s)
{
    int i,j,n;
    n=s.length();

    vector<vector<string>>All_parts;
    vector<string>curr_part;

    Find_all_pali_partitions_until(All_parts,curr_part,0,n,s);

    for(i=0;i<All_parts.size();i++)
    {
        for(j=0;j<All_parts[i].size();j++)
        {
            cout<<All_parts[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    Find_all_palindromic_partitions(s);   
}