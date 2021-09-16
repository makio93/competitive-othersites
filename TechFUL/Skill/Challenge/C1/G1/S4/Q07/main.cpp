#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int by, bm, bd, bh, bm2, ny, nm, nd, nh, nm2;
    cin >> by >> bm >> bd >> bh >> bm2 >> ny >> nm >> nd >> nh >> nm2;
    ll bi = (((by * 12LL + bm) * 30LL + bd) * 24LL + bh) * 60LL + bm2;
    ll ni = (((ny * 12LL + nm) * 30LL + nd) * 24LL + nh) * 60LL + nm2;
    ll di = ni - bi;
    int dm2 = di % 60, dh = di / 60 % 24, dd = di / (60LL*24) % 30, dm = di / (60LL*24*30) % 12, dy = di / (60LL*24*30*12);
    cout << dy << ' ' << dm << ' ' << dd << ' ' << dh << ' ' << dm2 << endl;
    return 0;
}
