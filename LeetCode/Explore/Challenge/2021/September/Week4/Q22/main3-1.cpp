#include <bits/stdc++.h>
using namespace std;

// 解説AC3-1

class Solution {
    int dfs(vector<string>& arr, int pos, string ccnt) {
        unordered_set<char> cset(ccnt.begin(), ccnt.end());
        if (cset.size() != ccnt.length()) return 0;
        int res = ccnt.length();
        for (int i=pos; i<(int)(arr.size()); ++i) res = max(res, dfs(arr, i+1, ccnt+arr[i]));
        return res;
    }
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return dfs(arr, 0, "");
    }
};
