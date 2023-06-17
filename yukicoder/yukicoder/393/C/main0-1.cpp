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

double dist(int r, double x, double y) {
	return sqrt((r-x)*(r-x) + (r-y)*(r-y));
}

int main() {
	int r, k;
	cin >> r >> k;
	random_device seed_gen;
	mt19937 engine(seed_gen());
	vector<pair<double, double>> plst;
	plst.reserve((k+1)*10000);
	while ((int)(plst.size()) < (k+1)*10000) {
		double yi = engine() / (double)(1LL<<32) * 2 * r, xi = engine() / (double)(1LL<<32) * 2 * r;
		if (dist(r, xi, yi) > (double)r) continue;
		plst.emplace_back(yi, xi);
	}
	sort(all(plst));
	vector<double> res(k);
	rep(i, k) res[i] = sqrt((plst[(i+1)*10000].first * plst[(i+1)*10000-1].first)) - r;
	rep(i, k) cout << fixed << setprecision(10) << res[i] << endl;
	return 0;
}
