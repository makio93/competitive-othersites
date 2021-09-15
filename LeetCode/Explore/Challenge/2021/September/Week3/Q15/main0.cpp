#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), res = 1, val = 1;
        for (int i=0; i<n-1; ++i) {
            if ((i%2==0&&arr[i]<arr[i+1]) || (i%2==1&&arr[i]>arr[i+1])) { ++val; res = max(res, val); }
            else val = 1;
        }
        val = 1;
        for (int i=0; i<n-1; ++i) {
            if ((i%2==0&&arr[i]>arr[i+1]) || (i%2==1&&arr[i]<arr[i+1])) { ++val; res = max(res, val); }
            else val = 1;
        }
        return res;
    }
};
