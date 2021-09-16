// 本番AC

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    for (int i=0; i<m; ++i) cin >> l[i] >> r[i];
    vector<int> sub(n+1);
    for (int i=0; i<m; ++i) { sub[l[i]-1]++; sub[r[i]]--; }
    for (int i=0; i<n; ++i) sub[i+1] += sub[i];
    int cnt = 0;
    for (int i=0; i<n; ++i) if (sub[i] == 0) ++cnt;
    cout << cnt << endl;
    return 0;
}
