#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (!((n>=3)&&(arr[0]<arr[1])&&(arr[n-2]>arr[n-1]))) return false;
        bool fin = false;
        for (int i=1; i+1<n-1; ++i) {
            if (arr[i] == arr[i+1]) return false;
            if (!fin) { if (arr[i] > arr[i+1]) fin = true; }
            else { if (arr[i] < arr[i+1]) return false; }
        }
        return true;
    }
};
