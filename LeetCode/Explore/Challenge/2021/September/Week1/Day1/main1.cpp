#include <bits/stdc++.h>
using namespace std;

// 解説AC

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<bool> visited(n);
        for (int i=0; i<n; ++i) if (!visited[i]) {
            int cnt = 0, now = i;
            while (!visited[now]) {
                visited[now] = true;
                ++cnt;
                now = nums[now];
            }
            res = max(res, cnt);
        }
        return res;
    }
};
