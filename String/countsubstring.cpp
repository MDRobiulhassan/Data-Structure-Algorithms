//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    long long int substrCount(string s, int k)
    {
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
    }

    long long int atMostKDistinct(string s, int k)
    {
        int n = s.size();
        unordered_map<char, int> m;

        long long int j = 0, count = 0;

        for (long long int i = 0; i < n; i++)
        {
            m[s[i]]++;

            while (m.size() > k)
            {
                m[s[j]]--;

                if (m[s[j]] == 0)
                    m.erase(s[j]);
                j++;
            }
            count += i - j + 1;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.substrCount(s, k) << endl;
    }
}
// } Driver Code Ends