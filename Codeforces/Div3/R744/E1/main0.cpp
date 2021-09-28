#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> p(n);
		rep(i, n) cin >> p[i];
		deque<int> dq;
		dq.push_back(p[0]);
		rep3(i, 1, n) {
			if (dq.front() > p[i]) dq.push_front(p[i]);
			else dq.push_back(p[i]);
		}
		rep(i, n) printf("%d%c", dq[i], (i<n-1?' ':'\n'));
	}
	return 0;
}
