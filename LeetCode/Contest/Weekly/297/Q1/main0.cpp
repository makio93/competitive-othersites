// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        int sum = 0;
        for (int i=0; i<n; ++i) {
            if (income == 0) break;
            if (i-1 >= 0) {
                int val = min(income, brackets[i][0]-brackets[i-1][0]);
                sum += val * brackets[i][1];
                income -= val;
            }
            else {
                int val = min(income, brackets[i][0]);
                sum += val * brackets[i][1];
                income -= val;
            }
        }
        return sum / 100.0;
    }
};
