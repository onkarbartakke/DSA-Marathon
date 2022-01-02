#include <bits/stdc++.h>

using namespace std;

class AllOne
{
    public:
    unordered_map<string, int> freq;

    class Node
    {
        public:
        unordered_set<string> bag;
        int f;
        Node *prev;
        Node *next;

        Node(string key, int fe)
        {
            f = fe;
            bag.insert(key);
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node *> listptr;
    Node *head;
    Node *tail;

    AllOne()
    {

        head = NULL;
        tail = NULL;
    }

    void remove_node(Node *p)
    {
        if (p == head)
        {
            head = head->next;

            if (head == NULL)
            {
                tail = NULL;
            }
            else
            {
                head->prev = NULL;
            }
        }
        else if (p == tail)
        {
            tail = tail->prev;
            if (tail == NULL)
                head = NULL;
            else
                tail->next = NULL;
        }
        else
        {
            Node *pe, *ne;
            ne = p->next;
            pe = p->prev;

            ne->prev = pe;
            pe->next = ne;
        }

        delete p;
        return;
    }

    void insert_between(Node *pe, Node *ne, Node *n)
    {
        if (pe == NULL && ne == NULL)
        {
            head = n;
            tail = n;
        }
        else if (pe == NULL)
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
        else if (ne == NULL)
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        else
        {
            pe->next = n;
            n->prev = pe;

            n->next = ne;
            ne->prev = n;
        }
    }
    void inc(string key)
    {

        if (freq.find(key) != freq.end())
        {
            int old_freq = freq[key];
            freq[key]++;

            Node *p = listptr[old_freq];
            p->bag.erase(key);

            int new_freq = old_freq + 1;

            if (listptr.find(new_freq) != listptr.end())
            {
                Node *q = listptr[new_freq];
                q->bag.insert(key);
            }
            else
            {
                Node *pe = p;
                Node *ne;
                if (p != tail)
                {
                    ne = p->next;
                }
                else
                {
                    ne = NULL;
                }
                Node *n = new Node(key, new_freq);
                insert_between(pe, ne, n);
                listptr[new_freq] = n;
            }

            if (p->bag.empty())
            {
                remove_node(p);
                listptr.erase(old_freq);
            }
        }
        else
        {
            freq[key] = 1;

            if (listptr.find(1) != listptr.end())
            {
                Node *p = listptr[1];
                p->bag.insert(key);
            }
            else
            {
                if (head == NULL && tail == NULL)
                {
                    head = new Node(key, 1);
                    tail = head;
                }
                else
                {
                    Node *h = new Node(key, 1);
                    h->next = head;
                    head->prev = h;
                    head = h;
                }

                listptr[1] = head;
            }
        }
    }

    void dec(string key)
    {

        if (freq[key] > 1)
        {
            int old_freq = freq[key];
            int new_freq = old_freq - 1;
            freq[key]--;

            Node *p = listptr[old_freq];
            p->bag.erase(key);

            if (listptr.find(new_freq) != listptr.end())
            {
                Node *q = listptr[new_freq];
                q->bag.insert(key);
            }
            else
            {
                Node *ne, *pe;
                ne = p;
                if (p != head)
                {
                    pe = p->prev;
                }
                else
                {
                    pe = NULL;
                }

                Node *n = new Node(key, new_freq);
                insert_between(pe, ne, n);
                listptr[new_freq] = n;
            }

            if (p->bag.empty())
            {
                remove_node(p);
                listptr.erase(old_freq);
            }
        }
        else if (freq[key] == 1)
        {
            Node *p = listptr[1];
            p->bag.erase(key);

            freq.erase(key);

            if (p->bag.empty())
            {
                remove_node(p);
                listptr.erase(1);
            }
        }
    }

    string getMaxKey()
    {
        string ret = "";
        if (tail != NULL)
        {
            for (auto it : tail->bag)
                return it;
        }

        return ret;
    }

    string getMinKey()
    {
        string ret = "";
        if (head != NULL)
        {
            for (auto it : head->bag)
                return it;
        }

        return ret;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */