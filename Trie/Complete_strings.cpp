#include<bits/stdc++.h>

using namespace std;

/*

Given an arrays of string, a complete string is that string whoes all prefixes are present in the array.
return the longest complete string if exists else return "none" and if more tha one longest cpmplete string exits return lexographically shortest one*/


class Node
{
    public:
    Node *links[26];
    int precount;
    int endcount;

    Node()
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            links[i] = NULL;
        }

        precount = 0;
        endcount = 0;
    }

    int getpre()
    {
        return precount;
    }

    int getend()
    {
        return endcount;
    }

    void increasePre()
    {
        precount++;
    }

    void increaseEnd()
    {
        endcount++;
    }

    bool containsKey(char c)
    {
        if(links[c - 'a'])
        return true;
        else
        return false;
    }

    void put(char c)
    {
        links[c - 'a'] = new Node;
    }

    Node* getLink(char c)
    {
        return links[c - 'a'];
    }
};


class Trie
{
    public:
    Node *root;
    Trie()
    {
        root = new Node;
    }

    void insert(string key)
    {
        Node *n = root;

        for(int i = 0 ; i < key.length() ; i++)
        {
            if(!n->containsKey(key[i]))
            {
               n->put(key[i]);
            }
            
            n = n->getLink(key[i]);
            n->increasePre();
        }

        n->increaseEnd();
    }

    int NumberOfprefixes(string key)
    {
        Node *n = root;

        for(int i = 0 ; i< key.length() ; i++)
        {
            if(!n->containsKey(key[i]))
            return 0;

            n = n->getLink(key[i]);
        }

        return n->getpre();
    }


    int NumberOfEnds(string key)
    {
        Node *n = root;

        for(int  i = 0 ; i < key.length() ; i++)
        {
            if(n->containsKey(key[i]))
            n = n->getLink(key[i]);
            else
            return 0;
        }

        return n->getend();
    }


    bool isComplete(string key)
    {
        Node *n = root;

        for(int i = 0 ; i< key.length() ; i++)
        {
            if(n->containsKey(key[i]))
            {
                n = n->getLink(key[i]);

                if(n->getend() == 0)
                return false;
            }
            else
            return false;
        }

        return true;
    }


    string getLongestComplete(vector<string>&arr)
    {
        string longest = "";

        for(int i = 0 ; i< arr.size() ; i++)
        {
            if(arr[i].length() >= longest.length())
            {
                if(isComplete(arr[i]))
                {
                    if(arr[i].length() > longest.length())
                    longest = arr[i];
                    else if(arr[i].length() == longest.length() && arr[i].compare(longest) < 0)
                    longest = arr[i];
                }
            }
        }

        if(longest == "")
        return "None";
        else
        return longest;
    }
};


int main()
{

}
