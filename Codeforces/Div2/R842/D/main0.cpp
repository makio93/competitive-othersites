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
		int n;
		cin >> n;
		vector<int> p(n);
		rep(i, n) {
			cin >> p[i];
			p[i]--;
		}
		vector<int> ptar(n);
		iota(all(ptar), 0);
		if (p == ptar) {
			cout << 1 << endl;
			continue;
		}
		vector<bool> check(n);
		vector<vector<int>> ids;
		bool ok = false;
		rep(i, n) if (!check[i]) {
			check[i] = true;
			if (p[i] == i) continue;
			ids.push_back(vector<int>());
			ids.back().push_back(i);
			int id = i;
			while (!check[p[id]]) {
				id = p[id];
				check[id] = true;
				ids.back().push_back(id);
			}
			sort(all(ids.back()));
			if (ok) continue;
			int m = ids.back().size();
			rep(j, m-1) if (ids.back()[j]+1 == ids.back()[j+1]) {
				ok = true;
				break;
			}
		}
		int res = 0;
		for (const auto& vi : ids) res += vi.size() - 1;
		if (ok) --res;
		else ++res;
		cout << res << endl;
	}
	return 0;
}
