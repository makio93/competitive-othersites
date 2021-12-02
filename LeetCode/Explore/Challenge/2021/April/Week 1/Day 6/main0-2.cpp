#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) { return (n%2==0) ? (n*n/4) : ((n+1)*(n-1)/4); }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    cout << cl.minOperations(n) << endl;
    return 0;
}
