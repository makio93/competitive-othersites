// 本番WA

#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int q;
    cin >> q;
    for (int i1=0; i1<q; ++i1) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b >= a) {
            if (b < c) cout << 'X' << endl;
            else cout << 'Z' << endl;
        }
        else {
            if (b+d < a) {
                if (a+d <= c) cout << 'Z' << endl;
                else cout << 'Y' << endl;
            }
            else {
                ll yi = (min(d,a-b-1) + max(0LL,b+d-c)) * d * 2;
                if (b+d < c) {
                    ll x1 = max(0LL, (a-b)-(a+d-c)) * d * 2;
                    ll x2a = min(c-a, d-(a-b)), x2b = ((a-b) + (a-b+x2a-1)) * x2a;
                    ll xi = x1 + x2b;
                    if (xi > yi) cout << 'X' << endl;
                    else if (yi > xi) cout << 'Y' << endl;
                    else cout << 'Z' << endl;
                }
                else {
                    ll x2a = c-a, xi = ((a-b) + (a-b+x2a-1)) * x2a;
                    if (xi > yi) cout << 'X' << endl;
                    else if (yi > xi) cout << 'Y' << endl;
                    else cout << 'Z' << endl;
                }
            }
        }
    }
    return 0;
}
