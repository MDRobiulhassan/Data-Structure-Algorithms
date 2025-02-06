#include <bits/stdc++.h>
using namespace std;

void subsetsumk(int i, vector<int> &a, vector<int> &arr, int sum, int k)
{
    if (i == arr.size())
    {
        if (sum == k)
        {
            for (int j = 0; j < a.size(); j++)
                cout << a[j] << " ";
        cout << endl;
        }
        return;
    }

    a.push_back(arr[i]);
    subsetsumk(i + 1, a, arr, sum + arr[i], k);

    a.pop_back();
    subsetsumk(i + 1, a, arr, sum, k);
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    vector<int> a;
    subsetsumk(0, a, arr, 0, 2);

    return 0;
}