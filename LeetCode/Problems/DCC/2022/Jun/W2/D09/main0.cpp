// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> res(2);
        for (int i=0; i<n; ++i) {
            int id = lower_bound(numbers.begin()+i+1, numbers.end(), target-numbers[i]) - numbers.begin();
            if (id<n && numbers[i]+numbers[id]==target) {
                res[0] = i+1;
                res[1] = id + 1;
                break;
            }
        }
        return res;
    }
};
