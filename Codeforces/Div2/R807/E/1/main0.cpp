// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const int AMAX = (int)(2e5) + 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> acnt(AMAX+1);
    rep(i, n) acnt[a[i]]++;
    rep3(i, 1, AMAX+1) rep3r(j, 1, 25) if ((acnt[i])&(1<<j)) {
        acnt[i] ^= 1<<j;
        acnt[i+j]++;
    }
    map<int, int> bits;
    bits[0] = acnt[0];
    rep3(i, 1, AMAX+1) if (acnt[i] != acnt[i-1]) bits[i] = acnt[i];
    auto on = [&](auto on, int id) -> void {
        auto ritr = bits.upper_bound(id), litr = prev(ritr);
        if (litr->second == 0) {
            if (id == litr->first) {
                if (ritr==bits.end() || ritr->first>id+1) bits[id+1] = 0;
                else bits.erase(id+1);
                bits.erase(id);
            }
            else {
                if (ritr==bits.end() || ritr->first>id+1) bits[id+1] = 0;
                else bits.erase(id+1);
                bits[id] = 1;
            }
        }
        else {
            int rid = ritr->first;
            if (id == litr->first) {
                bits.erase(id);
                bits.erase(rid);
            }
            else {
                bits.erase(rid);
                bits[id] = 0;
            }
            on(on, rid);
        }
    };
    auto off = [&](auto off, int id) -> void {
        auto ritr = bits.upper_bound(id), litr = prev(ritr);
        int rid = ritr->first;
        if (litr->second == 1) {
            if (id == litr->first) {
                if (rid > id+1) bits[id+1] = 1;
                else bits.erase(rid);
                bits.erase(id);
            }
            else {
                if (rid > id+1) bits[id+1] = 1;
                else bits.erase(rid);
                bits[id] = 0;
            }
        }
        else {
            if (id == litr->first) {
                bits.erase(id);
                bits.erase(rid);
            }
            else {
                bits.erase(rid);
                bits[id] = 1;
            }
            off(off, rid);
        }
    };
    rep(i, q) {
        int k, l;
        cin >> k >> l;
        --k;
        off(off, a[k]);
        a[k] = l;
        on(on, a[k]);
        cout << (bits.rbegin()->first-1) << endl;
    }
    return 0;
}
