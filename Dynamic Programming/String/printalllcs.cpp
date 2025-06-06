// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends

// class Solution
// {
// public:
//     vector<vector<int> > dp;
//     set<string> lcsSet;

//     set<string> backtrack(const string &s, const string &t, int i, int j, vector<vector<int> > &dp, map<pair<int, int>, set<string> > &memo)
//     {
//         if (i == 0 || j == 0)
//             return {""};

//         if (memo.find({i, j}) != memo.end())
//             return memo[{i, j}];

//         set<string> result;

//         if (s[i - 1] == t[j - 1])
//         {
//             set<string> temp = backtrack(s, t, i - 1, j - 1, dp, memo);
//             for (const string &str : temp)
//                 result.insert(str + s[i - 1]);
//         }
//         else
//         {
//             if (dp[i - 1][j] >= dp[i][j - 1])
//             {
//                 set<string> top = backtrack(s, t, i - 1, j, dp, memo);
//                 result.insert(top.begin(), top.end());
//             }
//             if (dp[i][j - 1] >= dp[i - 1][j])
//             {
//                 set<string> left = backtrack(s, t, i, j - 1, dp, memo);
//                 result.insert(left.begin(), left.end());
//             }
//         }

//         return memo[{i, j}] = result;
//     }

//     vector<string> all_longest_common_subsequences(string s, string t)
//     {
//         int n = s.size(), m = t.size();
//         dp.assign(n + 1, vector<int>(m + 1, 0));

//         for (int i = 1; i <= n; ++i)
//         {
//             for (int j = 1; j <= m; ++j)
//             {
//                 if (s[i - 1] == t[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1] + 1;
//                 else
//                     dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }

//         map<pair<int, int>, set<string> > memo;
//         set<string> allLCS = backtrack(s, t, n, m, dp, memo);

//         vector<string> result(allLCS.begin(), allLCS.end());
//         sort(result.begin(), result.end());
//         return result;
//     }
// };
