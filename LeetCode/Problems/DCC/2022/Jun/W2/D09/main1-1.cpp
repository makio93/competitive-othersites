// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int li = 0, ri = n-1;
        while (li < ri) {
            if (numbers[li]+numbers[ri] == target) return { li+1, ri+1 };
            else if (numbers[li]+numbers[ri] > target) --ri;
            else ++li;
        }
        return { 0, 0 };
    }
};
