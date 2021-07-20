#include <bits/stdc++.h>
using namespace std;

// 提出1,自力AC

class Solution {
    int n;
    vector<int> origin, data;
public:
    Solution(vector<int>& nums) {
        n = nums.size();
        origin = data = nums;
        srand(time(NULL));
    }
    vector<int> reset() {
        data = origin;
        return data;
    }
    vector<int> shuffle() {
        deque<int> rest;
        for (int i=0; i<n; ++i) rest.push_back(data[i]);
        for (int i=0; i<n; ++i) {
            int id = rand() % (n - i);
            data[i] = rest[id];
            rest.erase(rest.begin()+id);
        }
        return data;
    }
};
