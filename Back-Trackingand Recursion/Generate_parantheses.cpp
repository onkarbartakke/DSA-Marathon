#include<iostream>
#include<vector>
#include<string>
using namespace std;

void find(int n,int open,int close, string s, vector<string>&ans)
{
    if(open>n || close>n || close>open)
    return;
    if(s.length()==(2*n) && open==close)
    {
        ans.push_back(s);
    }

    find(n,open+1,close,s+"(",ans);
    find(n,open,close+1,s+")",ans);
}

vector<string> Generate(int n)
{
    vector<string>ans;
    int open=0,close=0;
    string s="";
    find(n,open,close,s,ans);

    return ans;
}


int main()
{
    int n,i;
    cout<<"Enter Num of Paranthesis(num of pairs) : ";
    cin>>n;

    vector<string>ans;
    ans=Generate(n);
    cout<<"\n********************\n\n";
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
}