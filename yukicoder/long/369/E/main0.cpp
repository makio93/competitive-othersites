// 本番AC

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

const int INF = (int)(1e9);
using mint = modint998244353;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> ps(n, string(m, '0'));
	rep(i, m) {
		int li;
		cin >> li;
		rep(j, li) {
			int ai;
			cin >> ai;
			--ai;
			ps[ai][i] = '1';
		}
	}
	set<string> sst;
	rep(i, n) sst.insert(ps[i]);
	int len = sst.size();
	mint res = mint(2).pow(len);
	cout << res.val() << endl;
	return 0;
}
