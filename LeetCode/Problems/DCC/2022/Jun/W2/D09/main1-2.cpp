// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i=0; i<n; ++i) {
            int li = i+1, ri = n;
            while (ri-li > 1) {
                int ci = li + (ri-li) / 2;
                if (numbers[i]+numbers[ci] <= target) li = ci;
                else ri = ci;
            }
            if (numbers[i]+numbers[li] == target) return { i+1, li+1 };
        }
        return { 0, 0 };
    }
};
