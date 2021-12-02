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
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		priority_queue<pair<int, int>> que;
		rep(i, n) if (a[i] > 0) que.emplace(a[i], i);
		vector<pair<int, int>> res;
		while (que.size() > 1) {
			auto p1 = que.top(); que.pop();
			auto p2 = que.top(); que.pop();
			res.emplace_back(p1.second+1, p2.second+1);
			if (res.back().first > res.back().second) swap(res.back().first, res.back().second);
			p1.first--; p2.first--;
			if (p1.first > 0) que.push(p1);
			if (p2.first > 0) que.push(p2);
		}
		int k = res.size();
		cout << k << endl;
		rep(i, k) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
