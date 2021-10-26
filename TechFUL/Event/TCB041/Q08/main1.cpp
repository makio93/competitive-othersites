// 解説AC

#include <iostream>
#include <map>
#include <tuple>
using namespace std;
using ll = long long;

map<tuple<int, int, int>, ll> memo;
ll calc(int l, int r, int k) {
    if (memo.find({l, r, k}) != memo.end()) return memo[{l, r, k}];
    if (l<0 || r<0 || k<0) return (memo[{l, r, k}] = 0);
    else if (l > r) return (memo[{l, r, k}] = calc(r, l, k));
    else if (k == 0) return (memo[{l, r, k}] = l+1);
    else if (l == 0) {
        if (k <= r) return (memo[{l, r, k}] = 1);
        else return (memo[{l, r, k}] = 0);
    }
    else {
        if (k%2 == 0) return (memo[{l, r, k}] = calc(l/2, r/2, k/2) + calc((l-1)/2, (r-1)/2, k/2));
        else return (memo[{l, r, k}] = calc((l-1)/2, r/2, k/2) + calc(l/2, (r-1)/2, k/2));
    }
}

int main() {
    int q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        int li, ri, ki;
        cin >> li >> ri >> ki;
        if (ki == 0) cout << 0 << endl;
        else {
            ll res = (calc(ri, ri, ki) + calc(li-1, li-1, ki) - 2 * calc(li-1, ri, ki)) / 2;
            cout << res << endl;
        }
    }
    return 0;
}
