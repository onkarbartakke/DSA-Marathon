#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
    public:
    int capacity;
    int curr_size = 0;
    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> mp;

    void refresh(int key, int val)
    {
        cache.erase(mp[key]);
        cache.push_front(make_pair(key, val));
        mp[key] = cache.begin();
    }

    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            refresh(key, (*mp[key]).second);
            return (*mp[key]).second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            refresh(key, value);
        }
        else
        {
            cache.push_front(make_pair(key, value));
            mp[key] = cache.begin();

            if (mp.size() > capacity)
            {
                mp.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};