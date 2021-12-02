#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else {
            int nval1 = 1, nval2 = 0, nval = nval1 + nval2;
            for (int i=3; i<=n; ++i) {
                nval2 = nval1;
                nval1 = nval;
                nval = nval1 + nval2;
            }
            return nval;
        }
    }
};

int main(){
    
    return 0;
}
