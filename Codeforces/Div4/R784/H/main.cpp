// 

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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		vector<int> bcnt(31);
		repr(i, 31) rep(j, n) if ((a[j]>>i)&1) bcnt[i]++;
		int res = 0;
		repr(i, 31) {
			if (bcnt[i]+k >= n) {
				res |= (1<<i);
				k -= (n-bcnt[i]);
			}
		}
		cout << res << endl;
	}
	return 0;
}
