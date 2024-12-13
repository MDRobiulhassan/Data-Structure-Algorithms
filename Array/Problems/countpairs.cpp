#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &a, int l, int r, int mid)
    {
        vector<int> temp;
        int left = l, right = mid + 1;
        while (left <= mid && right <= r)
        {
            if (a[left] <= a[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else
            {
                temp.push_back(a[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(a[left]);
            left++;
        }
        while (right <= r)
        {
            temp.push_back(a[right]);
            right++;
        }
        for (int i = l; i <= r; i++)
        {
            a[i] = temp[i - l];
        }
    }
    int countpairs(vector<int> &nums, int low, int mid, int high)
    {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > 2 * (long long)nums[right])
                right++;
            count += right - (mid + 1);
        }
        return count;
    }
    int mergeSort(vector<int> &nums, int l, int r)
    {
        int count = 0;
        if (l == r)
            return count;
        int mid = (l + r) / 2;
        count += mergeSort(nums, l, mid);
        count += mergeSort(nums, mid + 1, r);
        count += countpairs(nums, l, mid, r);
        merge(nums, l, r, mid);
        return count;
    }

    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};