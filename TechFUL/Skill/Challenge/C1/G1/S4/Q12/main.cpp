#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> d(n);
    for (int i=0; i<n; ++i) cin >> d[i];
    ll sum = 0;
    int fcnt = 0;
    for (int i=0; i<n; ++i) {
        if (d[i]>=a && d[i]<=b) sum += d[i];
        else ++fcnt;
    }
    if (fcnt == n) cout << "uso" << endl;
    else {
        cout << fcnt << endl;
        double ave = round(sum*(ll)(1e4)/(double)(n-fcnt)) / (1e4);
        printf("%.4f\n", ave);
    }
    return 0;
}
