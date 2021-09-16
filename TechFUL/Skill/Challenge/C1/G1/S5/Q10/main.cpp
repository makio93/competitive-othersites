#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    int hval = 0, lval = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] > 0) hval += a[i];
        else if (a[i] < 0) lval += a[i];
    }
    cout << (hval-lval) << endl;
    return 0;
}
