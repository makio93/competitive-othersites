#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
    void dfs(vector<int>& lst, string& val, int low, int high) {
        if (!val.empty()) {
            long long rval = stoll(val);
            if (rval > (long long)high) return;
            if (rval >= (long long)low) lst.push_back((int)rval);
            int dig = val.back() - '0';
            if (dig+1 <= 9) {
                val += (char)(dig+1+'0');
                dfs(lst, val, low, high);
                val.pop_back();
            }
        }
        else {
            for (int i=1; i<=9; ++i) {
                val += (char)(i+'0');
                dfs(lst, val, low, high);
                val.pop_back();
            }
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string val;
        dfs(res, val, low, high);
        sort(res.begin(), res.end());
        return res;
    }
};
