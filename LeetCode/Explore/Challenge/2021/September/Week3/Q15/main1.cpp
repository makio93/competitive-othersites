#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
    int compare(int a, int b) { return (a>b) ? 1 : (a<b) ? -1 : 0; }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 1, li = 0;
        for (int i=1; i<n; ++i) {
            int cval = compare(arr[i-1], arr[i]);
            if (cval == 0) li = i;
            else if (i+1>=n || cval*compare(arr[i],arr[i+1])!=-1) {
                res = max(res, i-li+1);
                li = i;
            }
        }
        return res;
    }
};
