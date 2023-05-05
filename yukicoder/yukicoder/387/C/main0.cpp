// 本番WA

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

using mint = modint998244353;

int main() {
	int w, h;
	cin >> w >> h;
	vector<int> gids(10, -1);
	vector<bool> used(w);
	dsu d(w);
	bool zero = false;
	rep(i, h) {
		string q;
		cin >> q;
		if (zero) {
			cout << 0 << endl;
			continue;
		}
		rep(j, 10) {
			rep(k, w) if (q[k] == (char)('0'+j)) {
				if (!used[k]) used[k] = true;
				int ai = d.leader(k);
				if (count(all(gids), ai) >= 1) {
					if (gids[j] != ai) {
						zero = true;
						break;
					}
				}
				else {
					if (gids[j] == -1) gids[j] = ai;
					else {
						d.merge(k, gids[j]);
						gids[j] = d.leader(k);
					}
				}
			}
			if (zero) break;
		}
		if (zero) {
			cout << 0 << endl;
			continue;
		}
		vector<int> aids(26, -1);
		rep(j, 26) {
			int di = -1;
			rep(k, w) if (q[k] == (char)('a'+j)) {
				if (!used[k]) used[k] = true;
				int ai = d.leader(k);
				if (di!=-1 && gids[di]!=ai) {
					zero = true;
					break;
				}
				if (count(all(gids), ai) >= 1) {
					if (di == -1) di = find(all(gids), ai) - gids.begin();
				}
				if (aids[j] == -1) aids[j] = ai;
				else {
					int ti = find(all(gids), aids[j]) - gids.begin();
					if (ti<10 && di!=-1 && ti!=di) {
						zero = true;
						break;
					}
					if (ti<10 && di==-1) di = ti;
					else if (ti>=10 && di!=-1) gids[di] = aids[j];
					d.merge(k, aids[j]);
					aids[j] = d.leader(k);
					if (ti < 10) gids[ti] = aids[j];
				}
			}
			if (zero) break;
		}
		if (zero) {
			cout << 0 << endl;
			continue;
		}
		rep(j, 26) if (aids[j]!=-1 && find(all(gids),aids[j])!=gids.end()) aids[j] = -1;
		unordered_set<int> ast;
		rep(j, 26) if (aids[j] != -1) ast.insert(aids[j]);
		int fcnt = count(all(used), false) + (int)(ast.size());
		cout << mint(10).pow(fcnt).val() << endl;
	}
	return 0;
}
