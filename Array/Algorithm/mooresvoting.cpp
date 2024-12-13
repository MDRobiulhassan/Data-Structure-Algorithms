#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Moores voting algo
    int majorityElement(vector<int> &nums)  
    {
        int count = 0, el;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)  //check for new section
            {
                count = 1;
                el = nums[i];
            }
            else if (nums[i] == el)  //check if the elemnt mathces or not
                count++;
            else
                count--;
        }

        //checking if the element appears more than n/2
        count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == el)
                count++;
        }

        if (count > nums.size() / 2)
            return el;
        return -1;
    }
};