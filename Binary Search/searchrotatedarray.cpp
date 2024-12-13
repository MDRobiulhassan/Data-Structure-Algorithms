#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& a, int target) {
        int l = 0, r = a.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (a[mid] == target)
                return mid;
            if (a[l] <= a[mid]) {
                if (target >= a[l] && target <= a[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target <= a[r] && target >= a[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};