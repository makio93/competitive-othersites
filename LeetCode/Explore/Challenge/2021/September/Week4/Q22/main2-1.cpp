#include <bits/stdc++.h>
using namespace std;

// 解説AC2-1

class Solution {
    int dfs(vector<string>& arr, int pos, unordered_map<char, int>& ccnt) {
        for (auto pi : ccnt) if (pi.second > 1) return 0;
        int res = ccnt.size();
        for (int i=pos; i<(int)(arr.size()); ++i) {
            for (char ci : arr[i]) ccnt[ci]++;
            res = max(res, dfs(arr, i+1, ccnt));
            for (char ci : arr[i]) {
                ccnt[ci]--;
                if (ccnt[ci] == 0) ccnt.erase(ci);
            }
        }
        return res;
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        unordered_map<char, int> ccnt;
        return dfs(arr, 0, ccnt);
    }
};
