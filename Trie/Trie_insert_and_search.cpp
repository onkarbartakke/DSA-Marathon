#include<iostream>
#include<algorithm>

using namespace std;

class Trie_Node
{
    public:
    char data;
    Trie_Node* child[26];
    int word_end; 
};


Trie_Node* create_Node(char c='/')
{
    Trie_Node *T=new Trie_Node;
    T->data=c;
    T->word_end=0;
    for(int i=0;i<26;i++)
    {
        T->child[i]=NULL;
    }

    return T;
}

void insert(Trie_Node *Root, string key)
{
    int i,l;
    l=key.length();
    Trie_Node *T=Root;
    for(i=0;i<l;i++)
    {
        if(T->child[key[i]-'a']==NULL)
        {
            T->child[key[i]-'a']=create_Node(key[i]);
            T=T->child[key[i]-'a'];
        }
        else
        {
            T=T->child[key[i]-'a'];
        }
    }
    T->word_end++;
}

bool search(Trie_Node *Root, string key)
{
    int i,l;
    l=key.length();
    Trie_Node *T=Root;

    for(i=0;i<l;i++)
    {
        if(!T->child[key[i]-'a'])
        return false;
        else
        {
            T=T->child[key[i]-'a'];
            if(T->data!=key[i])
            return false;
        }
    }

    if(T->word_end>0)
    return true;
    else
    return false; 
}

int main()
{
    int i,n,j;
    cout<<"Enter the strings  elements  to be inserted : ";
    cin>>n;
    string s[n];

    cout<<"\nEnter the N string Elements : \n";
    Trie_Node *Root=NULL;
    Root=create_Node();
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        insert(Root,s[i]);
    }

    cout<<"\nEnter the num Elements to be searched : ";

    cin>>n;
    cout<<"\nEnter elements : \n";
    for(i=0;i<n;i++)
    {
        string x;
        cin>>x;
        if(search(Root,x))
        cout<<"\nString Found \n";
        else
        cout<<"\nString Not Found \n";
    }
}
