// 練習0,自力AC

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
	vector<int> a;
	while (1) {
		int ai;
		cin >> ai;
		if (ai == 0) break;
		a.push_back(ai);
	}
	int m = a.size(), mval = 0;
	rep(i, m) mval = max(mval, a[i]);
	vector<int> vals, odds;
	int nval = 1;
	while ((ll)nval*(nval+1)*(nval+2)/6 <= mval) {
		vals.push_back(nval*(nval+1)*(nval+2)/6);
		++nval;
	}
	int len1 = vals.size();
	rep(i, len1) if (vals[i]%2 == 1) odds.push_back(vals[i]);
	int len2 = odds.size();
	vector<int> dp1(mval+1, INF), dp2(mval+1, INF);
	dp1[0] = dp2[0] = 0;
	rep(i, len1) rep3(j, vals[i], mval+1) dp1[j] = min(dp1[j], dp1[j-vals[i]]+1);
	rep(i, len2) rep3(j, odds[i], mval+1) dp2[j] = min(dp2[j], dp2[j-odds[i]]+1);
	rep(i, m) cout << dp1[a[i]] << ' ' << dp2[a[i]] << endl;
	return 0;
}
