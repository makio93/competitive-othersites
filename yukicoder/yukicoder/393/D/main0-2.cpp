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

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<tuple<int, int, int>> xy;
	rep(i, n) xy.emplace_back(x[i], y[i], i);
	sort(all(xy));
	vector<pair<int, int>> res;
	for (int i=0; i+1<n; i+=2) res.emplace_back(get<2>(xy[i])+1, get<2>(xy[i+1])+1);
	int k = res.size();
	cout << k << endl;
	rep(i, k) cout << res[i].first << ' ' << res[i].second << endl;
	return 0;
}
