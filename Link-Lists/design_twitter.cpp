#include<bits/stdc++.h>

using namespace std;

class Twitter {
    public:

    class tweetNode
    {
        public:
        int tweetId;
        int userId;
        tweetNode *next;
        
        tweetNode(int uid, int tid)
        {
            userId = uid;
            tweetId = tid;
            next = NULL;
        }
    };

    tweetNode *tweetHead;
    unordered_map<int,unordered_set<int>> userTweetMap;    

    Twitter() {
        tweetHead = NULL;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetNode *n = new tweetNode(userId,tweetId);

        if(tweetHead)
        {
            n->next = tweetHead;
            tweetHead = n;
        }
        else
        {
            tweetHead = n;
        }
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int>feed;
        tweetNode *temp = tweetHead;

        while(temp && feed.size() < 10)
        {
            if((userTweetMap[userId].find(temp->userId) != userTweetMap[userId].end()) || userId == temp->userId)
            {
                feed.push_back(temp->tweetId);
            }
            
            temp = temp->next;
        }     

        return feed;   
    }
    
    void follow(int followerId, int followeeId) {

        userTweetMap[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
        userTweetMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */