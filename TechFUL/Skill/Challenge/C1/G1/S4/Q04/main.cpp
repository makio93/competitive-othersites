#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    ll val1 = 1, val2 = 1;
    for (int i=0; i<n; ++i) val1 *= m;
    for (int i=0; i<3; ++i) val2 *= m;
    cout << abs(val1-val2) << endl;
    return 0;
}
