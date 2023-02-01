#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size();
        sort(milestones.rbegin(), milestones.rend());
        long long sum = 0;
        for (int i=1; i<n; ++i) sum += milestones[i];
        return (sum + min(sum+1, (long long)milestones[0]));
    }
};
