#include <bits/stdc++.h>

using namespace std;

class LFUCache
{
    public:
    unordered_map<int, pair<int, int>> mp;
    unordered_map<int, list<int>::iterator> kIter;
    unordered_map<int, list<int>> freq;

    int size;
    int cap;
    int minfreq;
    LFUCache(int capacity)
    {
        cap = capacity;
        size = 0;
        minfreq = 0;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        int retval = mp[key].first;
        int old_f = mp[key].second;

        freq[old_f].erase(kIter[key]);
        mp[key].second = old_f + 1;

        freq[mp[key].second].push_back(key);
        kIter[key] = --(freq[mp[key].second].end());

        if (freq[minfreq].size() == 0)
            minfreq++;

        return retval;
    }

    void put(int key, int value)
    {

        if (cap <= 0)
            return;

        int prev_val = get(key); //Update if already exist, count increases when called get

        if (prev_val != -1)
        {
            mp[key].first = value; //Update if already exist, count increases
            return;
        }

        if (size >= cap)
        {
            int k = freq[minfreq].front();
            mp.erase(k);
            kIter.erase(k);
            freq[minfreq].pop_front();
            size--;
        }

        mp[key] = {value, 1};
        minfreq = 1;
        freq[1].push_back(key);
        kIter[key] = --(freq[1].end());
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
}