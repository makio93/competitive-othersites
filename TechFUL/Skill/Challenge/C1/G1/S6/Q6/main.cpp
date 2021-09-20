#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> aval(n);
    int res = 0;
    for (int i=0; i<m; ++i) {
        int cnt = 0;
        for (int j=0; j<n; ++j) {
            int ai;
            cin >> ai;
            aval[j] += ai;
            if (aval[j]>=x && aval[j]<=y) ++cnt;
        }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}
