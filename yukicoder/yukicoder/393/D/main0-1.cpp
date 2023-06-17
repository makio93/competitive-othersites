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

const int INF = (int)(1e9);

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	unordered_map<int, set<pair<int, int>>> xlst, ylst;
	rep(i, n) {
		xlst[x[i]].emplace(y[i], i);
		ylst[y[i]].emplace(x[i], i);
	}
	dsu uf(n);
	for (const auto& pi : xlst) for (auto itr=pi.second.begin(); next(itr)!=pi.second.end(); ++itr) uf.merge(itr->second, next(itr)->second);
	for (const auto& pi : ylst) for (auto itr=pi.second.begin(); next(itr)!=pi.second.end(); ++itr) uf.merge(itr->second, next(itr)->second);
	auto glst = uf.groups();
	int res = 0;
	for (const auto& gi : glst) res += (int)(gi.size()) / 2;
	cout << res << endl;
	return 0;
}
