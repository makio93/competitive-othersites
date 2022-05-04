// 学習0回目,自力AC

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
	int k;
	cin >> k;
	vector<string> res(8, string(8, '.'));
	set<int> ridst, cidst;
	rep(i, 8) ridst.insert(i);
	rep(i, 8) cidst.insert(i);
	rep(i, k) {
		int ri, ci;
		cin >> ri >> ci;
		res[ri][ci] = 'Q';
		ridst.erase(ri);
		cidst.erase(ci);
	}
	vector<int> rid(all(ridst)), cid(all(cidst));
	int m = cid.size();
	vector<int> ord(m);
	iota(all(ord), 0);
	do {
		auto tmp = res;
		rep(i, m) tmp[rid[i]][cid[ord[i]]] = 'Q';
		auto check = [&](int ri, int ci) -> bool {
			const vector<int> dr = { -1, -1, 0, 1, 1, 1, 0, -1 };
			const vector<int> dc = { 0, 1, 1, 1, 0, -1, -1, -1 };
			rep(i1, 8) {
				int vr = ri + dr[i1], vc = ci + dc[i1];
				while (vr>=0 && vr<8 && vc>=0 && vc<8) {
					if (tmp[vr][vc] == 'Q') return false;
					vr += dr[i1]; vc += dc[i1];
				}
			}
			return true;
		};
		bool ok = true;
		rep(i, 8) {
			rep(j, 8) if (tmp[i][j] == 'Q') {
				if (!check(i, j)) ok = false;
				if (!ok) break;
			}
			if (!ok) break;
		}
		if (ok) {
			res = tmp;
			break;
		}
	} while (next_permutation(all(ord)));
	rep(i, 8) cout << res[i] << endl;
	return 0;
}
