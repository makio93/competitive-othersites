// 解説AC2

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
const int INF = (int)(1e9);
vector<ll> two;
tuple<int, int, int, ll, int> op(tuple<int, int, int, ll, int> a, tuple<int, int, int, ll, int> b) {
	if (get<4>(b) == -1) return a;
	if (get<4>(a) == -1) return b;
	if (get<4>(b)<get<2>(b) || get<1>(a)>=get<0>(b)) return make_tuple(get<0>(a), get<1>(b), get<2>(a)+get<2>(b), get<3>(b), get<4>(b));
	return make_tuple(get<0>(a), get<1>(b), get<2>(a)+get<2>(b), (get<3>(a)+((get<3>(b)-get<0>(b)+mod)*2+get<0>(b))%mod*two[get<4>(a)-1]%mod)%mod, get<4>(a)+get<4>(b));
}

tuple<int, int, int, ll, int> e() { return make_tuple(-INF, -INF, 0, -INF, -1); }

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	two.assign(n+1, 0);
	two[0] = 1;
	rep(i, n) two[i+1] = two[i] * 2 % mod;
	segtree<tuple<int, int, int, ll, int>, op, e> st(n);
	rep(i, n) st.set(i, make_tuple(a[i], a[i], 1, a[i], 1));
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		ll res = get<3>(st.prod(li, ri));
		cout << res << endl;
	}
	return 0;
}
