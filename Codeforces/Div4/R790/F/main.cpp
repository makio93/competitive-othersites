// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9) + 5;

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
		map<int, int> acnt;
		rep(i, n) acnt[a[i]]++;
		pair<int, pair<int, int>> mval = { -1, make_pair(INF, -1) };
		int l = INF, r = -1;
		for (auto pi : acnt) {
			if (pi.second >= k) {
				if (l == INF) { l = pi.first; r = pi.first; }
				else { r = pi.first; }
				mval = max(mval, { r-l, make_pair(l, r) });
				if (acnt.find(pi.first+1)==acnt.end() || (acnt.find(pi.first+1)!=acnt.end()&&acnt[pi.first+1]<k)) l = INF;
			}
		}
		if (mval.first == -1) cout << -1 << endl;
		else cout << mval.second.first << ' ' << mval.second.second << endl;
	}
	return 0;
}
