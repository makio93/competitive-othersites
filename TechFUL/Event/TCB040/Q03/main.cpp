#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    bool ok = true;
    for (int i=0; i<n; ++i) if (!(a[i]>=l && a[i]<r)) ok = false;
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
