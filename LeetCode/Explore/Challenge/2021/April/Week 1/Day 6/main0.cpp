#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        for (int i=0; i<n; ++i) if (i*2+1 < n) res += n - (i*2+1);
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    cout << cl.minOperations(n) << endl;
    return 0;
}
