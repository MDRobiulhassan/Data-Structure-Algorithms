#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int getSecondLargest(vector<int> &arr)
	{
		int mx = -1;
		int secMax = -1;

		for (int x : arr)
		{
			if (x > mx)
			{
				secMax = mx;
				mx = x;
			}
			else if (x < mx && x > secMax)
			{
				secMax = x;
			}
		}

		return secMax;
	}
};