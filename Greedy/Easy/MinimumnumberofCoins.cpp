#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // vector<int> notes = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

        // Due to complier issue
        int arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> notes(arr, arr + sizeof(arr) / sizeof(arr[0]));

        vector<int> ans;
        int i = 0;
        while (N != 0)
        {
            while (notes[i] <= N)
            {
                N -= notes[i];
                ans.push_back(notes[i]);
            }
            i++;
        }

        return ans;
    }
};