#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	int getSecondLargest(vector<int> &arr)
	{
		int n = arr.size();
		int mx = -1;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mx)
				mx = arr[i];
		}

		int secMax = -1;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] != mx && arr[i] > secMax)
				secMax = arr[i];
		}

		return secMax;
	}
};