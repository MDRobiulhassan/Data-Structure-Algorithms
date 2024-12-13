#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = m + n;
        int gap = (len / 2) + (len % 2); // Initial gap

        while (gap > 0)
        {
            int l = 0;
            int r = l + gap;

            while (r < len)
            {
                // Case 1: Both pointers in nums1
                if (l < m && r < m)
                {
                    if (nums1[l] > nums1[r])
                    {
                        swap(nums1[l], nums1[r]);
                    }
                }
                // Case 2: l in nums1, r in nums2
                else if (l < m && r >= m)
                {
                    if (nums1[l] > nums2[r - m])
                    {
                        swap(nums1[l], nums2[r - m]);
                    }
                }
                // Case 3: Both pointers in nums2
                else if (l >= m)
                {
                    if (nums2[l - m] > nums2[r - m])
                    {
                        swap(nums2[l - m], nums2[r - m]);
                    }
                }

                l++;
                r++;
            }

            // Reduce the gap for the next iteration
            if (gap == 1)
            {
                break;
            }
            gap = (gap / 2) + (gap % 2); 
        }

        // Place elements from nums2 into their correct positions in nums1
        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
    }
};
