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
		int n;
		cin >> n;
		vector<int> w(n);
		rep(i, n) cin >> w[i];
		map<ll, int> rcnt;
		rcnt[0] = n;
		ll rsum = 0;
		repr(i, n) {
			rsum += w[i];
			rcnt[rsum] = i;
		}
		int res = 0;
		ll sum = 0;
		rep(i, n) {
			sum += w[i];
			if (rcnt.find(sum)!=rcnt.end() && i<rcnt[sum]) res = max(res, (i+1)+(n-rcnt[sum]));
		}
		cout << res << endl;
	}
	return 0;
}
