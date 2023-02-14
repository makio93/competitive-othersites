// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

const ull AF = ~0ULL;
class BitSet {
    int n, bl;
    vector<ull> bs;
    int get(int id) {
        if (bs[id/64]&(1ULL<<(id%64))) return 1;
        else return 0;
    }
    int get1(int id) {
        ull mask = ~((1ULL<<(id%64)) - 1);
        int bid = id / 64;
        if (bs[bid]&mask) return bid * 64 + __builtin_ctzll(bs[bid]&mask);
        ++bid;
        while (bs[bid] == 0ULL) ++bid;
        return bid * 64 + __builtin_ctzll(bs[bid]);
    }
    int get0(int id) {
        ull mask = ~((1ULL<<(id%64)) - 1);
        int bid = id / 64;
        if ((~bs[bid])&mask) return bid * 64 + __builtin_ctzll((~bs[bid])&mask);
        ++bid;
        while ((~bs[bid]) == 0ULL) ++bid;
        return bid * 64 + __builtin_ctzll(~bs[bid]);
    }
    void flip(int li, int ri) {
        int bli = li / 64, bri = ri / 64;
        bs[bli] ^= (1ULL << (li % 64)) - 1;
        if (ri%64 < 63) bs[bri] ^= (1ULL << (ri%64+1)) - 1;
        else bs[bri] ^= AF;
        if (bri > bli) {
            bs[bli] ^= AF;
            rep3(bid, bli+1, bri) bs[bid] ^= AF;
        }
    }
public:
    BitSet(int n_) {
        n = n_;
        bl = (n+63) / 64;
        bs.resize(bl);
    }
    void add(int id) {
        int zi = get0(id);
        flip(id, zi);
    }
    void del(int id) {
        int zi = get1(id);
        flip(id, zi);
    }
    int get_max() {
        repr(bi, bl) if (bs[bi] != 0ULL) return bi * 64 + 63 - __builtin_clzll(bs[bi]);
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), k(q), l(q);
    rep(i, n) cin >> a[i];
    rep(i, q) {
        cin >> k[i] >> l[i];
        k[i]--;
    }
    int mval = max(*max_element(all(a)), *max_element(all(l))) + 20;
    BitSet ab(mval);
    rep(i, n) ab.add(a[i]);
    rep(i, q) {
        ab.del(a[k[i]]);
        a[k[i]] = l[i];
        ab.add(a[k[i]]);
        cout << ab.get_max() << endl;
    }
    return 0;
}
