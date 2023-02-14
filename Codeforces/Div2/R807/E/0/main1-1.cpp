// 解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct BitSet {
    vector<ull> arr;
    BitSet(int n) : arr((n+63)/64+5) {}
    void flip(int li, int ri) {
        arr[li/64] ^= (1ULL<<(li%64))-1;
        arr[ri/64] ^= (1ULL<<(ri%64))-1;
        rep3(i, li/64, ri/64) arr[i] = ~arr[i];
    }
    int rget1(int li) {
        ull msk = ~((1ULL<<(li%64))-1);
        if (arr[li/64]&msk) return li/64*64 + __builtin_ctzll(arr[li/64]&msk);
        int id = li / 64 + 1;
        while (arr[id] == 0ULL) ++id;
        return id * 64 + __builtin_ctzll(arr[id]);
    }
    int rget0(int li) {
        ull msk = ~((1ULL<<(li%64))-1);
        if ((~arr[li/64])&msk) return li/64*64 + __builtin_ctzll((~arr[li/64])&msk);
        int id = li / 64 + 1;
        while (arr[id] == ~0ULL) ++id;
        return id * 64 + __builtin_ctzll(~arr[id]);
    }
    int mxget() {
        int id = arr.size() - 1;
        while (arr[id] == 0ULL) --id;
        return (id+1) * 64 - __builtin_clzll(arr[id]) - 1;
    }
    void add(int id) { flip(id, rget0(id)+1); }
    void sub(int id) { flip(id, rget1(id)+1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), ki(q), li(q);
    int mval = 0;
    rep(i, n) {
        cin >> a[i];
        mval = max(mval, a[i]);
    }
    rep(i, q) {
        cin >> ki[i] >> li[i];
        ki[i]--;
        mval = max(mval, li[i]);
    }
    BitSet bs(mval);
    rep(i, n) bs.add(a[i]);
    rep(i, q) {
        bs.sub(a[ki[i]]);
        a[ki[i]] = li[i];
        bs.add(li[i]);
        cout << bs.mxget() << endl;
    }
    return 0;
}
