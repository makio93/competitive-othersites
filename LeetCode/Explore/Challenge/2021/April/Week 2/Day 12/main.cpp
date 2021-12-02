#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        int val = k + 1, sub = k;
        for (int i=k; i>=0; --i) {
            res[i] = val;
            if ((k-i)%2 == 0) val -= sub;
            else val += sub;
            --sub;
        }
        for (int i=k+1; i<n; ++i) res[i] = i + 1;
        return res;
    }
};

int main(){
    Solution cl;
    int n, k;
    cin >> n >> k;
    auto res = cl.constructArray(n, k);
    for (int i=0; i<n; ++i) printf("%d%c", res[i], (i<n-1?' ':'\n'));
    return 0;
}
