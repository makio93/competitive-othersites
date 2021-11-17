#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> p(n);
    for (int i=0; i<n; ++i) cin >> p[i];
    cin >> m;
    vector<int> a(m+1), b(m), c(m+1);
    for (int i=0; i<m+1; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    for (int i=0; i<m+1; ++i) cin >> c[i];
    vector<int> res(n);
    for (int i=0; i<n; ++i) {
        int val = 0;
        for (int j=0; j<m; ++j) if (p[i] >= a[j]) val += (min(p[i], b[j]) - a[j]) * c[j] / 100;
        if (p[i] >= a[m]) val += (p[i] - a[m]) * c[m] / 100;
        res[i] = val;
    }
    for (int i=0; i<n; ++i) {
        cout << res[i];
        if (i < n-1) cout << ' ';
    }
    cout << endl;
    return 0;
}
