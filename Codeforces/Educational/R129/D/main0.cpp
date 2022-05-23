// 本番AC

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

int main() {
	int n;
	ull x;
	cin >> n >> x;
	map<ull, int> dist;
	priority_queue<pair<int, ull>, vector<pair<int, ull>>, greater<pair<int, ull>>> pq;
	dist[x] = 0;
	pq.emplace(0, x);
	int res = INF;
	while (!pq.empty()) {
		auto pi = pq.top(); pq.pop();
		int di = pi.first; ull val = pi.second;
		if (dist.find(val)==dist.end() || dist[val]!=di) continue;
		string xstr = to_string(val);
		for (char yi='2'; yi<='9'; ++yi) if (xstr.find(yi) != string::npos) {
			ull nval = val * (int)(yi-'0'); int ndi = di + 1;
			if ((int)(to_string(nval).length()) > n) continue;
			if ((int)(to_string(nval).length()) == n) {
				res = min(res, ndi);
				continue;
			}
			if (dist.find(nval)!=dist.end() && dist[nval]<=ndi) continue;
			dist[nval] = ndi;
			pq.emplace(ndi, nval);
		}
	}
	if (res == INF) cout << -1 << endl;
	else cout << res << endl;
	return 0;
}
