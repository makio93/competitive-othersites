#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> sub(30, vector<int>(n+1));
    for (int i=0; i<q; ++i) {
        int li, ri, xi;
        cin >> li >> ri >> xi;
        --li;
        for (int j=0; j<30; ++j) {
            if (xi&1) { sub[j][li]++; sub[j][ri]--; }
            xi >>= 1;
        }
    }
    for (int i=0; i<30; ++i) {
        for (int j=0; j<n; ++j) sub[i][j+1] += sub[i][j];
        for (int j=0; j<n; ++j) sub[i][j] %= 2;
    }
    vector<int> a(n);
    for (int i=0; i<n; ++i) for (int j=0; j<30; ++j) if (sub[j][i] > 0) a[i] += (1<<j);
    for (int i=0; i<n; ++i) printf("%d%c", a[i], (i<n-1?' ':'\n'));
    return 0;
}
