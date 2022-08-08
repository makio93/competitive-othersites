// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int len;
    vector<int> data;
    void init(int len) {
        this->len = len;
        data.resize(len+1);
    }
    void update(int id, int val) {
        while (id <= len) {
            data[id] = max(data[id], val);
            id += id & -id;
        }
    }
    int query(int id) {
        int val = 0;
        while (id) {
            val = max(val, data[id]);
            id -= id & -id;
        }
        return val;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lval = *min_element(nums.begin(), nums.end()), rval = *max_element(nums.begin(), nums.end());
        init(rval-lval+1);
        for (int i=0; i<n; ++i) {
            int nval = query(nums[i]-lval);
            update(nums[i]-lval+1, nval+1);
        }
        return query(len);
    }
};
