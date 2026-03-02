#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> following;

    // userId -> list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // global timer to maintain tweet order
    int time = 0;

    Twitter()
    {
        // Constructor (nothing special needed)
    }

    // User posts a tweet
    void postTweet(int userId, int tweetId)
    {

        // Store tweet with current timestamp
        tweets[userId].push_back({time, tweetId});

        // Increase time for next tweet
        time++;
    }

    // Retrieve 10 most recent tweets
    vector<int> getNewsFeed(int userId)
    {

        // Max heap to get most recent tweets first
        // pair<timestamp, tweetId>
        priority_queue<pair<int, int>> maxHeap;

        // Ensure user sees their own tweets
        following[userId].insert(userId);

        // Go through all people this user follows
        for (int followee : following[userId])
        {

            // Push all tweets of that followee into heap
            for (auto &tweet : tweets[followee])
            {
                maxHeap.push(tweet);
            }
        }

        vector<int> result;

        // Extract top 10 most recent tweets
        int count = 0;
        while (!maxHeap.empty() && count < 10)
        {
            result.push_back(maxHeap.top().second); // tweetId
            maxHeap.pop();
            count++;
        }

        return result;
    }

    // followerId follows followeeId
    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    // followerId unfollows followeeId
    void unfollow(int followerId, int followeeId)
    {

        // Prevent user from unfollowing themselves
        if (followeeId != followerId)
        {
            following[followerId].erase(followeeId);
        }
    }
};