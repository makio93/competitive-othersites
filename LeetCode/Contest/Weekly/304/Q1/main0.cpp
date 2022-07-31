// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> vals;
        vals.insert(0);
        for (int& val : nums) vals.insert(val);
        return (int)(vals.size()) - 1;
    }
};
