// 自力AC

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    int n;
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        int _n = nums.size();
        n = 1;
        while (n < _n) n *= 2;
        data.assign(n+1, 0);
        for (int i=0; i<_n; ++i) {
            int val = nums[i], id = i+1;
            while (id <= n) {
                data[id] += val;
                id += id & -id;
            }
        }
    }
    void update(int index, int val) {
        int sub = val - sumRange(index, index);
        int id = index + 1;
        while (id <= n) {
            data[id] += sub;
            id += id & -id;
        }
    }
    int sumRange(int left, int right) {
        return sumAll(right+1) - sumAll(left);
    }
    int sumAll(int id) {
        int sum = 0;
        while (id > 0) {
            sum += data[id];
            id -= id & -id;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
