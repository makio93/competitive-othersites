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
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int mval = max({ m, l, *max_element(all(a)) });
	vector<vector<int>> memo(n+1, vector<int>(mval+1, -1));
	auto calc = [&](auto calc, int di, int ci) -> bool {
		if (memo[di][ci] != -1) return (memo[di][ci] == 1);
		if (di == n) return ((memo[di][ci] = (ci == m) ? 1 : 0) == 1);
		else {
			int rval = (calc(calc, di+1, ci) || calc(calc, di+1, (ci+a[di])/2)) ? 1 : 0;
			return ((memo[di][ci] = rval) == 1);
		}
	};
	if (calc(calc, 0, l)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
