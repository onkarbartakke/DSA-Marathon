#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node
{
    public:
    char data;
    Node *next;
    Node *prev;

    Node(char d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

string FirstNonRepeating(string A)
{
    // Code here
    //queue Approach
    /*
		    int hash[26]={0};
		    int i,j,n;
		    n=A.length();
		    
		    queue<char>qu;
		    string ans="";
		    for(i=0;i<n;i++)
		    {
		        if(hash[A[i]-'a']==0)
		        {
		            
		            
		            qu.push(A[i]);
		        }
		        hash[A[i]-'a']++;
		        while(!qu.empty() && hash[qu.front()-'a']>1)
		        {
		            qu.pop();
		        }
		        
		        if(!qu.empty())
		        {
		            ans=ans+qu.front();
		        }
		        else
		        {
		            ans=ans+"#";
		        }
		    }
		    
		    return ans;
		    */

    //DLL Approcach O(N)
    int n, i, j;
    n = A.length();
    string ans = "";
    int hash[26] = {0};

    Node *head, *tail;

    head = NULL;
    tail = NULL;

    Node *arr[26];
    for (i = 0; i < 26; i++)
    {
        arr[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        if (hash[A[i] - 'a'] == 0)
        {
            Node *t = new Node(A[i]);
            if (head == NULL)
            {
                head = t;
                tail = head;
            }
            else
            {

                tail->next = t;
                t->prev = tail;
                tail = t;
            }

            arr[A[i] - 'a'] = t;
        }
        else
        {
            Node *p = arr[A[i] - 'a'];

            if (p != NULL)
            {
                Node *left = p->prev;
                Node *right = p->next;

                if (p == head)
                {
                    head = head->next;

                    if (head)
                        head->prev = NULL;

                    p->next = NULL;
                    p->prev = NULL;
                }
                else if (p == tail)
                {
                    tail = tail->prev;

                    if (tail)
                        tail->next = NULL;

                    p->next = NULL;
                    p->prev = NULL;
                }
                else
                {
                    if (left)
                        left->next = right;

                    if (right)
                        right->prev = left;

                    p->next = NULL;
                    p->prev = NULL;
                }

                arr[A[i] - 'a'] = NULL;
            }
        }

        hash[A[i] - 'a']++;

        if (head != NULL)
        {
            ans.push_back(head->data);
        }
        else
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string s;
    cout<<"Enter the String S : ";
    cin>>s;

    string ans=FirstNonRepeating(s);

    cout<<"\n\n"<<ans;
}