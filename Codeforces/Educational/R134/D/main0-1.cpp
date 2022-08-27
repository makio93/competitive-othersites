// 本番WA1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		rep(i, n) cin >> a[i];
		rep(i, n) cin >> b[i];
		vector<int> rcnt(30);
		auto calc = [&](auto calc, int di, int li, int ri) -> void {
			if (di < 0) return;
			int len = ri - li;
			int acnt = 0, bcnt = 0;
			rep3(i, li, ri) if ((a[i]>>di)&1) ++acnt;
			rep3(i, li, ri) if ((b[i]>>di)&1) ++bcnt;
			if (acnt+bcnt != len) calc(calc, di-1, li, ri);
			else {
				rcnt[di] += len;
				sort(a.begin()+li, a.begin()+ri, [&](int v1, int v2) -> bool {
					return (v1 & (1<<di)) > (v2 & (1<<di));
				});
				sort(b.begin()+li, b.begin()+ri, [&](int v1, int v2) -> bool {
					return (v1 & (1<<di)) < (v2 & (1<<di));
				});
				if (acnt>0 && bcnt>0) {
					calc(calc, di-1, li, li+acnt);
					calc(calc, di-1, li+acnt, ri);
				}
				else calc(calc, di-1, li, ri);
			}
		};
		calc(calc, 29, 0, n);
		ll res = 0;
		rep(i, 30) if (rcnt[i] == n) res += 1<<i;
		cout << res << endl;
	}
	return 0;
}
