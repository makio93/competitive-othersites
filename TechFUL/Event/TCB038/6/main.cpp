#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll choose(int n, int r) {
    if (r < 0) return 0;
    if (n-r < r) return choose(n, n-r);
    ll res = 1;
    for (int i=1; i<=r; ++i) {
        res *= n - i + 1;
        res /= i;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i=0; i<m; ++i) cin >> a[i];
    ll res = 1;
    --n;
    for (int i=1; i<m; ++i) {
        res *= choose(n, a[i]);
        n -= a[i];
    }
    cout << res << endl;
    return 0;
}
