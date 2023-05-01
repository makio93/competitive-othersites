// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int lv = *min_element(salary.begin(), salary.end()), rv = *max_element(salary.begin(), salary.end());
        return (accumulate(salary.begin(), salary.end(), 0) - lv - rv) / (double)(n-2);
    }
};
