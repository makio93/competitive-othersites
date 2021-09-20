#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int val = a[0] + b[0];
    for (int i=1; i<n; ++i) val = min(val, a[i]+b[i]);
    cout << val << endl;
    return 0;
}
