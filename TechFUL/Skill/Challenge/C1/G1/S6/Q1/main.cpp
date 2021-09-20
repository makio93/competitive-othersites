#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> vl(n);
    for (int i=0; i<n; ++i) cin >> vl[i];
    cin >> m;
    vector<int> vi(m);
    for (int i=0; i<m; ++i) cin >> vi[i];
    bool ok = false;
    for (int i=0; i+n-1<m; ++i) {
        bool ok2 = true;
        for (int j=0; j<n; ++j) if (vi[i+j] != vl[j]) ok2 = false;
        if (ok2) ok = true;
    }
    if (ok) cout << "unlock" << endl;
    else cout << "lock" << endl;
    return 0;
}
