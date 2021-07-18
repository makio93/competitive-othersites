#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        vector<int> b;
        b.push_back(rungs.front());
        for (int i=0; i<n-1; ++i) b.push_back(rungs[i+1] - rungs[i]);
        int res = 0;
        for (int i=0; i<n; ++i) res += (b[i] + dist - 1) / dist - 1;
        return res;
    }
};

int main() {
    
    return 0;
}
