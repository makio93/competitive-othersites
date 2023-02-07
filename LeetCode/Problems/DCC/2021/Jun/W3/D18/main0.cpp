#include <bits/stdc++.h>
using namespace std;

// 自力AC

class NumArray {
    int n;
    vector<int> v, d;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        v = nums;
        d = vector<int>(n+1);
        for (int i=0; i<n; ++i) {
            int id = i + 1;
            while (id <= n) {
                d[id] += v[i];
                id+=id&-id;
            }
        }
    }
    void update(int index, int val) {
        int id = index + 1, add = val - v[index];
        v[index] = val;
        while (id <= n) {
            d[id] += add;
            id+=id&-id;
        }
    }
    int sumRange(int left, int right) {
        int lval = 0, rval = 0;
        ++right;
        while (left > 0) {
            lval += d[left];
            left-=left&-left;
        }
        while (right > 0) {
            rval += d[right];
            right-=right&-right;
        }
        return rval - lval;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
