#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& a) {
        int count = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i-1] > a[i])
                count++;
        }
        if (a[a.size()-1] > a[0])
            count++;
        
        return count <= 1;
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
    
    if (solution.check(a)) {
        cout << "The array can be rotated to form a non-decreasing array." << endl;
    } else {
        cout << "The array cannot be rotated to form a non-decreasing array." << endl;
    }

    return 0;
}
