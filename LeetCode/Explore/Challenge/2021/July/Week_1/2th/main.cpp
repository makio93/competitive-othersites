#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int, int>> vec(n);
        for (int i=0; i<n; ++i) vec[i] = { abs(arr[i]-x), arr[i] };
        sort(vec.begin(), vec.end());
        vector<int> res;
        for (int i=0; i<k; ++i) res.push_back(vec[i].second);
        sort(res.begin(), res.end());
        return res;
    }
};
