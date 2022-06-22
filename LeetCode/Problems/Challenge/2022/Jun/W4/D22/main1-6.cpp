// 解説AC6,ヒープソート

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), hsz = 0;
        auto repair = [&](auto repair, int id) -> void {
            int li = id * 2 + 1, ri = id * 2 + 2;
            pair<int, int> cval = { -INF, -INF };
            if (li < hsz) cval = max(cval, { nums[li], -li });
            if (ri < hsz) cval = max(cval, { nums[ri], -ri });
            if (cval.first > nums[id]) {
                swap(nums[id], nums[-cval.second]);
                repair(repair, -cval.second);
            }
        };
        auto build = [&]() {
            hsz = nums.size();
            for (int i=hsz/2-1; i>=0; --i) repair(repair, i);
        };
        build();
        for (int i=0; i<k-1; ++i) {
            swap(nums[0], nums[hsz-1]);
            --hsz;
            repair(repair, 0);
        }
        return nums[0];
    }
};
