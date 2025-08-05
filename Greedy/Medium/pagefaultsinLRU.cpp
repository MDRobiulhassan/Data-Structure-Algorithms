// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        list<int> cache;
        set<int> inCache;
        int faults = 0;

        for (int i = 0; i < N; i++)
        {
            int page = pages[i];

            // Page not in cache
            if (inCache.find(page) == inCache.end())
            {
                faults++;

                // If cache is full, remove least recently used
                if (cache.size() == C)
                {
                    int lru = cache.back();
                    cache.pop_back();
                    inCache.erase(lru);
                }
            }
            // Page in cache - remove old position
            else
            {
                cache.remove(page);
            }

            // Insert current page at front (most recently used)
            cache.push_front(page);
            inCache.insert(page);
        }

        return faults;
    }
};