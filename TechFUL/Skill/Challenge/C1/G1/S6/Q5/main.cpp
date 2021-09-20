#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> row(n), col(n);
    int dig = 0, rdig = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        int ai;
        cin >> ai;
        row[i] += ai;
        col[j] += ai;
        if (i == j) dig += ai;
        if (i+j == n-1) rdig += ai;
    }
    bool ok = true;
    for (int i=0; i<n; ++i) if (row[i] != dig) ok = false;
    for (int i=0; i<n; ++i) if (col[i] != dig) ok = false;
    if (dig != rdig) ok = false;
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
