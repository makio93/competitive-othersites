// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    int n;
    vector<int> vals, data;
public:
    NumArray(vector<int>& nums) {
        int n_ = nums.size();
        vals = nums;
        n = 1;
        while (n < n_) n *= 2;
        data.assign(2*n-1, 0);
        for (int i=0; i<n_; ++i) {
            int id = i + n-1;
            data[id] = nums[i];
            while (id > 0) {
                id = (id-1) / 2;
                data[id] = data[id*2+1] + data[id*2+2];
            }
        }
    }
    void update(int index, int val) {
        int sub = val - vals[index];
        vals[index] = val;
        index += n-1;
        data[index] += sub;
        while (index > 0) {
            index = (index-1) / 2;
            data[index] = data[index*2+1] + data[index*2+2];
        }
    }
    int sumRange(int left, int right, int id=0, int li=0, int ri=-1) {
        if (ri == -1) { ri = n; id = 0; li = 0; ++right; }
        if (ri<=left || right<=li) return 0;
        if (left<=li && ri<=right) return data[id];
        else {
            int vl = sumRange(left, right, id*2+1, li, (li+ri)/2);
            int vr = sumRange(left, right, id*2+2, (li+ri)/2, ri);
            return vl + vr;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
