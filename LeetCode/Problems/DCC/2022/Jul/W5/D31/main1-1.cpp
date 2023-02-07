// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class NumArray {
    int n, len;
    vector<int> vals, backet;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        len = (int)(ceil(sqrt(n))+0.5);
        vals = nums;
        backet.assign(len, 0);
        for (int i=0; i<n; ++i) backet[i/len] += nums[i];
    }
    void update(int index, int val) {
        backet[index/len] += val - vals[index];
        vals[index] = val;
    }
    int sumRange(int left, int right) {
        int sum = 0, li = (left+len-1) / len, ri = (right+1) / len;
        if (li > ri) for (int i=left; i<=right; ++i) sum += vals[i];
        else {
            for (int i=left; i<li*len; ++i) sum += vals[i];
            for (int i=li; i<ri; ++i) sum += backet[i];
            for (int i=ri*len; i<=right; ++i) sum += vals[i];
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
