#include<iostream>
#include<stack>
#include<string>

using namespace std;

int  postfixVal(string s)
{
    stack<int>st;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9') 
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op1, op2;
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();

            int ans;

            if(s[i]=='+')
            ans=op1+op2;
            else if(s[i]=='-')
            ans=op1-op2;
            else if(s[i]=='*')
            ans=op1*op2;
            else if(s[i]=='/')
            ans=op1/op2;

            st.push(ans);
        }   
    }

    int a=st.top();
    return a;
}
int main()
{
    string s;
    cout<<"Enter the postfix Expression : ";
    cin>>s;
    cout<<"\nExpression value is :  "<<postfixVal(s);
}