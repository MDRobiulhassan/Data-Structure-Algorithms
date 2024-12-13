#include <bits/stdc++.h>
using namespace std;

bool countstudent(vector<int> &arr, int i, int m) {
  long long pages = 0; 
  int count = 1;
  for (int j = 0; j < arr.size(); j++) {
    if (pages + arr[j] <= i)
      pages += arr[j];
    else {
      count++;
      pages = arr[j];
    }
  }
  return count == m;
}

int findPages(vector<int> &arr, int n, int m) {
  if (n < m)
    return -1;
  int l = *max_element(arr.begin(), arr.end());
  int r = accumulate(arr.begin(), arr.end(), 0);

  for (int i = l; i <= r; i++) {
    if (countstudent(arr, i, m))
      return i;
  }
  return l;
}