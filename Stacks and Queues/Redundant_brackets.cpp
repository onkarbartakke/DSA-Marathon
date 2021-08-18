#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;
bool redudant_brackets(string s)
{
    stack<char>st;
    int i,j;
    bool ans=false;
    for(i=0;i<s.length();i++)
    {
       if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*')
       st.push(s[i]);
       else if(s[i]=='(')
       st.push(s[i]);
       else if(s[i]==')')
       {
           if(st.top()=='(' || st.empty())
           {
               ans=true;
               break;
           }
           
           while((!st.empty()) && (st.top()=='+' || st.top()=='/' || st.top()=='-' || st.top()=='*'))
           {
               st.pop();
           }

           if(st.top()=='(')
           st.pop();
       }
    }

    return ans;
}
int main()
{
    string s;
    cout<<"Enter the Expression : ";
    cin>>s;

    if(redudant_brackets(s))
    {
        cout<<"Redudant Brackets Exists\n";
    }
    else
    {
        cout<<"Redudant Brackets dont Exists";
    }
}
