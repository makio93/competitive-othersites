#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int wt, sb, lb, n, p;
    cin >> wt >> sb >> lb >> n >> p;
    int lnum = p / n;
    ll sumlb = (ll)lnum * lb, sumsb = (ll)(p-lnum) * sb, sumwt = (ll)wt * p;
    cout << sumwt << endl;
    cout << sumsb << endl;
    cout << sumlb << endl;
    return 0;
}
