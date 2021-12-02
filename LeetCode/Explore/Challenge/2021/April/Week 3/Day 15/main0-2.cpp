#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else {
            vector<int> fval(n+1);
            fval[0] = 0; fval[1] = 1;
            for (int i=2; i<=n; ++i) fval[i] = fval[i-2] + fval[i-1];
            return fval[n];
        }
    }
};

int main(){
    
    return 0;
}
