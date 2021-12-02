#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    inline int minOperations(int n) { return n*n/4; }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    cout << cl.minOperations(n) << endl;
    return 0;
}
