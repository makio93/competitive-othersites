// 解説AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        ll sum = accumulate(target.begin(), target.end(), 0LL);
        int id = max_element(target.begin(), target.end()) - target.begin();
        while (sum > n) {
            sum -= target[id];
            if (target[id]<sum || sum==0 || (sum>1&&target[id]%sum==0)) return false;
            if (sum == 1) target[id] = sum;
            else target[id] %= sum;
            sum += target[id];
            id = max_element(target.begin(), target.end()) - target.begin();
        }
        return true;
    }
};
