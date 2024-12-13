#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int removeDuplicates(vector<int>& nums) {
        set<int> a;
        for(int i = 0; i < nums.size(); i++) {
            a.insert(nums[i]);
        }
        
        nums.clear();
        // for(auto it : a) {
        //     nums.push_back(it);
        // } needed
        return a.size();
    }
};

int main() {
    Solution solution;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int newSize = solution.removeDuplicates(a);
    
    cout << "New size of array after removing duplicates: " << newSize << endl;
    cout << "Array after removing duplicates: ";
    for(int i=0;i<newSize;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
