// 本番,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0) : d(n, -1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return (d[x] = find(d[x]));
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return (find(x) == find(y)); }
	int size(int x) { return -d[find(x)]; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		UnionFind u(n);
		vector<pair<int, int>> res;
		deque<pair<int, int>> pq;
		int dcnt = 0;
		rep(i, n) if (s[i] == '0') {
			pq.emplace_back(2, i);
			dcnt += 2;
		}
		rep(i, n) if (s[i] == '1') {
			pq.emplace_back(1, i);
			dcnt += 1;
		}
		if ((n-1)*2%2!=dcnt%2 || (n-1)*2<dcnt) {
			cout << "NO" << endl;
			continue;
		}
		if ((n-1)*2 != dcnt) {
			int dsub = (n-1)*2 - dcnt;
			for (auto& pi : pq) {
				pi.first += 2;
				dsub -= 2;
				if (dsub == 0) break;
			}
		}
		int cnt = 0;
		while (pq.size() > 1) {
			auto pi1 = pq.front(); pq.pop_front();
			auto pi2 = pq.front(); pq.pop_front();
			++cnt;
			while (u.same(pi1.second, pi2.second)) {
				pq.push_back(pi2);
				pi2 = pq.front(); pq.pop_front();
				++cnt;
				if (cnt > n*100) break;
			}
			if (cnt > n*100) break;
			res.emplace_back(pi1.second+1, pi2.second+1);
			u.unite(pi1.second, pi2.second);
			pi1.first--; pi2.first--;
			if (pi1.first > 0) pq.push_front(pi1);
			if (pi2.first > 0) pq.push_back(pi2);
		}
		if ((int)(res.size()) != n-1) {
			cout << "NO" << endl;
			continue;
		}
		else {
			cout << "YES" << endl;
			rep(i, n-1) cout << res[i].first << ' ' << res[i].second << endl;
		}
	}
	return 0;
}
