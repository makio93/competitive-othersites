#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[arr[i]]++;
        vector<int> cnts;
        for (auto ci : vcnt) cnts.push_back(ci.second);
        sort(cnts.rbegin(), cnts.rend());
        int sum = 0, res = -1, m = cnts.size();
        for (int i=0; i<m; ++i) {
            sum += cnts[i];
            if (sum >= n/2) {
                res = i+1;
                break;
            }
        }
        return res;
    }
};
