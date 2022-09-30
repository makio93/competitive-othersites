// 本番AC

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
		vector<int> par(n), deg(n);
		rep3(i, 1, n) {
			cin >> par[i];
			par[i]--;
			deg[par[i]]++;
		}
		int lval = 0, rval = n;
		while (rval-lval > 1) {
			int cval = rval - (rval-lval) / 2;
			auto tdeg = deg;
			queue<int> que;
			vector<int> dist(n);
			int kcnt = 0;
			rep(i, n) if (tdeg[i] == 0) que.push(i);
			while (!que.empty()) {
				int vi = que.front(); que.pop();
				int di = dist[vi], ndi = di + 1;
				if (ndi>=cval && par[vi]!=0) {
					++kcnt;
					ndi = 0;
				}
				tdeg[par[vi]]--;
				dist[par[vi]] = max(dist[par[vi]], ndi);
				if (tdeg[par[vi]]==0 && par[vi]!=0) que.push(par[vi]);
			}
			if (kcnt <= k) rval = cval;
			else lval = cval;
		}
		cout << rval << endl;
	}
	return 0;
}
