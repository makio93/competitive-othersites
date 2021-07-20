#include <bits/stdc++.h>
using namespace std;

// 提出2,シャッフル処理をサボるとWA

class Solution {
    int n, pre;
    vector<int> origin, data1, data2;
public:
    Solution(vector<int>& nums) {
        n = nums.size();
        pre = 0;
        origin = nums;
        srand(time(NULL));
        deque<int> rest1, rest2;
        for (int i=0; i<n; ++i) rest1.push_back(origin[i]);
        rest2 = rest1;
        for (int i=0; i<n; ++i) {
            int id = rand() % (n - i);
            data1.push_back(rest1[id]);
            rest1.erase(rest1.begin()+id);
        }
        for (int i=0; i<n; ++i) {
            int id = rand() % (n - i);
            data2.push_back(rest2[id]);
            rest2.erase(rest2.begin()+id);
        }
    }
    vector<int> reset() {
        return origin;
    }
    vector<int> shuffle() {
        pre = 1 - pre;
        return (pre==0 ? data1 : data2);
    }
};
