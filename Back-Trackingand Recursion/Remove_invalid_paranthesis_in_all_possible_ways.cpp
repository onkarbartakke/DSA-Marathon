#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>

using namespace std;
vector<string>ans;


bool isParanthesis(char c)
{
    if(c=='(' || c==')')
    return true;
    else
    return false;
}

bool isValid(string s)
{
    int i,n,count=0;
    n=s.length();
    i=0;
    while(i<n)
    {
        if(s[i]=='(')
        count++;
        else if(s[i]==')')
        {
            count--;

            if(count<0)
            return false;
        }

        i++;
    }

    return (count==0);
}


void Generate_valids(string s)
{
    int i,j,n;
    n=s.length();
    if(n==0)
    return;

    if(isValid(s))
    {
        ans.push_back(s);
        return;
    }

    queue<string>qu;
    set<string>visit;

    qu.push(s);
    visit.insert(s);
    bool level=false;

    while(!qu.empty())
    {
        string c=qu.front();
        qu.pop();

        if(isValid(c))
        {
            ans.push_back(c);
            level=true;
        }

        if(level)
        continue;

        for(int i=0; i<c.length();i++)
        {
            if(!isParanthesis(c[i]))
            continue;
            

            string temp=c.substr(0,i)+c.substr(i+1);

            if(visit.find(temp)==visit.end())
            {
                visit.insert(temp);
                qu.push(temp);
            }
        }

    }
}


int main()
{
    string s;
    cout<<"Enter the Expression : ";
    cin>>s;

   Generate_valids(s);

    cout<<"\n\n";
    int i;
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }


}