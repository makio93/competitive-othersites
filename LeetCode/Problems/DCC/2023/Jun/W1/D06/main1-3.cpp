// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size(), lval = *min_element(arr.begin(), arr.end()), rval = *max_element(arr.begin(), arr.end());
        if ((rval-lval)%(n-1) != 0) return false;
        int dif = (rval - lval) / (n-1);
        if (dif == 0) return true;
        for (int i=0; i<n; ++i) {
            int tval = lval + i * dif;
            if (arr[i] == tval) continue;
            if ((arr[i]-lval)%dif != 0) return false;
            while (arr[i] != tval) {
                int ri = (arr[i] - lval) / dif;
                if ((arr[ri]-lval)/dif == ri) return false;
                swap(arr[ri], arr[i]);
            }
        }
        return true;
    }
};
