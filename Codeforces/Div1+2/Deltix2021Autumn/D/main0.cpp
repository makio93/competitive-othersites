#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

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
	int n, d;
	cin >> n >> d;
	UnionFind u(n);
	multiset<int> gvals;
	rep(i, n) gvals.insert(1);
	int cnt = 0;
	rep(i, d) {
		int xi, yi;
		cin >> xi >> yi;
		--xi; --yi;
		if (!u.same(xi, yi)) {
			int xval = u.size(xi), yval = u.size(yi);
			gvals.erase(gvals.find(xval));
			gvals.erase(gvals.find(yval));
			u.unite(xi, yi);
			gvals.insert(u.size(xi));
			++cnt;
		}
		int scnt = (i+1) - cnt + 1, res = 0;
		for (auto itr=gvals.rbegin(); itr!=gvals.rend(); ++itr) {
			res += *itr;
			--scnt;
			if (scnt <= 0) break;
		}
		cout << (res-1) << endl;
	}
	return 0;
}
