#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {

        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> freq;
        for (int card : hand)
            freq[card]++;

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto &it : freq)
            minHeap.push(it.first); // Push unique cards into the min heap

        while (!minHeap.empty())
        {

            int start = minHeap.top(); // Get the smallest card

            for (int i = 0; i < groupSize; i++)
            {

                int card = start + i; // Get the next card in the sequence

                if (freq[card] == 0)
                    return false; // If the card is not available, we cannot form a straight hand

                freq[card]--; // Use the card

                if (freq[card] == 0)
                {
                    if (card != minHeap.top())
                        return false; // If the card is not the smallest card, it means we have a gap in the sequence
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};