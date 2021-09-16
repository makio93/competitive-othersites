// 本番AC

#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int q;
    cin >> q;
    for (int i1=0; i1<q; ++i1) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b == a) {
            if (a == c) cout << 'Z' << endl;
            else if (d == 1) cout << 'Z' << endl;
            else cout << 'X' << endl;
        }
        else if (b > a) {
            if (b == c) cout << 'Z' << endl;
            else if (d == 1) cout << 'Z' << endl;
            else if (b+d <= c) {
                if (a+d <= b+1) cout << 'Z' << endl;
                else cout << 'X' << endl;
            }
            else {
                if (min(c,a+d) <= b) cout << 'Z' << endl;
                else cout << 'X' << endl;
            }
        }
        else {
            if (a == c) {
                if (b+1==c && d==1) cout << 'Z' << endl;
                else cout << 'Y' << endl;
            }
            else {
                ll xa1 = 0, xal = min(c, a+1), xah = min(c, a+d);
                if (b+d+2<=a+d && b+d+2<=c) {
                    xa1 = (min(c, a+d) - max(xal, b+d+2) + 1) * d;
                    xah = b + d + 1;
                }
                ll xb1 = 0, xb2 = 0;
                if (xah-xal >= 0) {
                    if (b+d > c) xb1 = (b+d-c) * (xah-xal+1);
                    xb2 = ((xal-b-1) + (xah-b-1)) * (xah-xal+1) / 2;
                }
                ll xval = xa1 + xb1 + xb2;
                ll yb1 = 0, yb2 = min(d, a-b-1) * d;
                if (b+d > c) yb1 = (b+d-c) * d;
                ll yval = yb1 + yb2;
                if (xval > yval) cout << 'X' << endl;
                else if (yval > xval) cout << 'Y' << endl;
                else cout << 'Z' << endl;
            }
        }
    }
    return 0;
}
