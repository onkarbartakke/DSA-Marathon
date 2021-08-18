#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isOperand(char c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z'))
    return true;
    else
    return false;
}

int precedenc(char c)
{
    if(c=='+' || c=='-')
    return 1;
    if(c=='*' || c=='/')
    return 2;
    if(c=='^')
    return 3;
    else 
    return -1;
}


string infix_to_postfix(string &s)
{
    stack<char>st;
    string p;
    int i;
  
    for(i=0;i<s.length();i++)
    {
       
        if(isOperand(s[i]))
        {
            p.push_back(s[i]);
        }
        else
        {
            if(st.empty())
            st.push(s[i]);
            else
            {
               if(s[i]=='(')
               st.push(s[i]);
               else if(s[i]==')')
               {
                   while(!st.empty() && st.top()!='(')
                   {
                       p.push_back(st.top());
                       st.pop();
                   }
                   if(!st.empty())
                   st.pop();

               }
               else
               {
                   while(!st.empty() && precedenc(st.top())>=precedenc(s[i]))
                   {
                       p.push_back(st.top());
                       st.pop();
                   }

                   st.push(s[i]);
               }
            }
        }
    }

    while(!st.empty())
    {
        p.push_back(st.top());
        st.pop();
    }

    return p;
}


int main()
{
    string s;
    cout<<"Enter the Expression: ";
    cin>>s;

    string postfix=infix_to_postfix(s);

    cout<<"Postfix Expression is : "<<postfix;
}