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
		int n, d12, d23, d31;
		cin >> n >> d12 >> d23 >> d31;
		vector<pair<int, int>> res;
		int li = -1, ci = -1, ri = -1, ld = -1, rd = -1, cd = -1;
		if (d12 >= max(d23, d31)) {
			if (d12>d23+d31 || (d23+d31-d12)%2!=0) {
				cout << "NO" << endl;
				continue;
			}
			li = 1; ci = 3; ri = 2;
			cd = (d23+d31-d12)/2, ld = d31 - cd, rd = d23 - cd;
		}
		else if (d23 >= max(d12, d31)) {
			if (d23>d12+d31 || (d12+d31-d23)%2!=0) {
				cout << "NO" << endl;
				continue;
			}
			li = 2; ci = 1; ri = 3;
			cd = (d12+d31-d23)/2, ld = d12 - cd, rd = d31 - cd;
		}
		else if (d31 >= max(d12, d23)) {
			if (d31>d12+d23 || (d12+d23-d31)%2!=0) {
				cout << "NO" << endl;
				continue;
			}
			li = 1; ci = 2; ri = 3;
			cd = (d12+d23-d31)/2, ld = d12 - cd, rd = d23 - cd;
		}
		else {
			cout << "NO" << endl;
			continue;
		}
		if (ld+rd+cd > n-1) {
			cout << "NO" << endl;
			continue;
		}
		int id = 4, tci = -1;
		if (ld == 1) {
			if (cd == 0) res.emplace_back(li, ci);
			else {
				tci = id; ++id;
				res.emplace_back(li, tci);
			}
		}
		else {
			res.emplace_back(li, id); ++id;
			rep(i, ld-2) { res.emplace_back(id-1, id); ++id; }
			if (cd == 0) res.emplace_back(id-1, ci);
			else {
				tci = id;
				res.emplace_back(id-1, tci); ++id;
			}
		}
		if (rd == 1) {
			if (cd == 0) res.emplace_back(ci, ri);
			else res.emplace_back(tci, ri);
		}
		else {
			if (cd == 0) res.emplace_back(ci, id);
			else res.emplace_back(tci, id);
			++id;
			rep(i, rd-2) { res.emplace_back(id-1, id); ++id; }
			res.emplace_back(id-1, ri);
		}
		if (cd != 0) {
			if (cd == 1) res.emplace_back(tci, ci);
			else {
				res.emplace_back(tci, id); ++id;
				rep(i, cd-2) { res.emplace_back(id-1, id); ++id; }
				res.emplace_back(id-1, ci);
			}
		}
		if (id <= n) { res.emplace_back(ri, id); ++id; }
		while (id <= n) { res.emplace_back(id-1, id); ++id; }
		int m = res.size();
		cout << "YES" << endl;
		rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
	}
	return 0;
}
