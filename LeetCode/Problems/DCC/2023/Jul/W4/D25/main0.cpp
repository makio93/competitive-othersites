// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size(), li = 1, ri = n;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2;
            if (arr[ci] > arr[ci-1]) li = ci;
            else ri = ci;
        }
        return li;
    }
};
