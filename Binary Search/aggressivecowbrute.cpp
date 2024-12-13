#include <bits/stdc++.h>
using namespace std;

bool canplace(vector<int> &stalls, int dist, int k) {
  int lastcow = stalls[0];
  int count = 1;

  for (int i = 1; i < stalls.size(); i++) {
    if (stalls[i] - lastcow >= dist) {
      count++;
      lastcow = stalls[i];
    }
    if (count >= k)
      return true;
  }
  return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
  int n = stalls.size();
  sort(stalls.begin(), stalls.end());
  int limit = stalls[n - 1] - stalls[0];

  for (int i = 1; i <= limit; i++) {
    if (!canplace(stalls, i, k))
      return i - 1;
  }
  return limit;
}