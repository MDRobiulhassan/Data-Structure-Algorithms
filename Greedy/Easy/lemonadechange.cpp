#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     bool lemonadeChange(vector<int> &bills)
//     {
//         int n = bills.size();

//         map<int, int> m;
//         bool flag = true;
//         for (int i = 0; i < n; i++)
//         {
//             if (bills[i] == 5)
//                 m[5]++;
//             else if (bills[i] == 10)
//             {
//                 if (m[5] >= 1)
//                 {
//                     m[5]--;
//                     m[10]++;
//                 }
//                 else
//                 {
//                     flag = false;
//                     break;
//                 }
//             }

//             else
//             {
//                 if (m[5] >= 1 && m[10] >= 1)
//                 {
//                     m[5]--;
//                     m[10]--;
//                 }
//                 else if (m[5] >= 3)
//                     m[5] -= 3;
//                 else
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//         }

//         return flag;
//     }
// };

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        int n = bills.size();

        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
            {
                five++;
            }
            else if (bills[i] == 10)
            {
                if (five == 0)
                    return false;
                five--;
                ten++;
            }
            else
            { // bill == 20
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
};
