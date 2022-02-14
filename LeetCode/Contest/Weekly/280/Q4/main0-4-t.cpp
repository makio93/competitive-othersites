// 終了後,自力考察,自力AC,ACL使用

#include <bits/stdc++.h>
#include <atcoder/mincostflow>
using namespace std;
using namespace atcoder;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        mcf_graph<int, int> g(n+numSlots*2+2);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<numSlots; ++j) {
                g.add_edge(i, n+j, 1, -(nums[i]&(j+1))+100);
                g.add_edge(i, n+numSlots+j, 1, -(nums[i]&(j+1))+100);
            }
        }
        for (int i=0; i<n; ++i) g.add_edge(n+numSlots*2, i, 1, 0);
        for (int i=0; i<numSlots*2; ++i) g.add_edge(n+i, n+numSlots*2+1, 1, 0);
        auto pval = g.flow(n+numSlots*2, n+numSlots*2+1);
        return -(pval.second-n*100);
    }
};
