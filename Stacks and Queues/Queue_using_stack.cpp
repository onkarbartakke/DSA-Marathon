#include<bits/stdc++.h>

using namespace std;

class Queue
{
    public:
    int N;
    stack<int>s1;
    stack<int>s2;

    Queue()
    {
        N=0;
    }

    void push(int x)
    {
        s2.push(x);
        N++;
        /*
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        */
    }

    int pop()
    {
        if(!s1.empty())
        {
            int x=s1.top();
            s1.pop();
            N--;
            return x;
        }
        else
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

            N--;
            int x=s1.top();
            s1.pop();
            return x;
        }
    }

    int front()
    {
        if(!s1.empty())
        {
            int x=s1.top();
            return x;
        }
        else
        {
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }

           
            int x=s1.top();
            return x;
        }   
    }

    int size()
    {
        if(N<0)
        return -1;
        else
        return N;
    }
};

int main()
{
    Queue qu;
    qu.push(1);  
    qu.push(2);  
    qu.push(3);  
    qu.push(4);   
    qu.push(5);
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n"; 
    cout<<qu.pop()<<"\n";  
}



bool isSame(string s, string p)
{
    if(s.length()!=p.length())
    return false;
    
    vector<int>cnt(26,0);
    for(int i = 0 ; i < s.length() ; i = i + 2)
    {
        cnt[s[i]-'a']++;
        cnt[p[i]-'a']--;
    }

    for(int i = 0 ; i < 26 ; i++)
    {
        if(cnt[i]!=0)
        return false;
    }


    for(int i = 1; i < s.length() ; i = i + 2)
    {
        cnt[s[i] - 'a']++;
        cnt[p[i]-'a']--;
    }

    for(int i = 0 ; i < 26 ; i++)
    {
        if(cnt[i]!=0)
        return false;
    }

    return true;

  
}


void check(string s, unordered_set<string>&st)
{
    for(auto it : st)
    {
        if(s.compare(it) == 0)
        continue;

        if(isSame(s,it))
        st.erase(it);
    }
}

int distinctPasswords(int n , string a[])
{
    unordered_set<string>st;

    for(int i = 0 ; i < n ; i++)
    {
        st.insert(a[i]);
    }

    for(auto it : st)
    {
        check(it,st);
    }

    return st.size();
}