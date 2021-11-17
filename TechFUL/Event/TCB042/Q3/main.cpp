#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<m; ++i) cin >> b[i];
    vector<int> cnt(101);
    for (int i=0; i<n; ++i) cnt[a[i]]++;
    int mval = 0;
    for (int i=1; i<=100; ++i) mval = max(mval, cnt[i]);
    int res = -1;
    if (mval == n) res = 0;
    else {
        for (int i=0; i<m; ++i) {
            cnt[b[i]]++;
            if (cnt[b[i]] == n) {
                res = i+1;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
