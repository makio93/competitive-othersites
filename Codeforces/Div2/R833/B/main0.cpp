// 本番WA

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
		string s;
		cin >> n >> s;
		vector<vector<int>> sums(n+1, vector<int>(10));
		rep(i, n) {
			sums[i+1][s[i]-'0']++;
			rep(j, 10) sums[i+1][j] += sums[i][j];
		}
		ll res = 0;
		rep(i, n) {
			int mid = 0;
			rep(j, 10) if (sums[i+1][j] > 0) ++mid;
			rep3(j, 1, mid+1) {
				if (j == mid) {
					int mval = 0;
					rep(j2, 10) mval = max(mval, sums[i+1][j2]);
					if (mval <= j) res += i+1;
				}
				else {
					int li = 0, ri = i;
					while (ri-li > 1) {
						int ci = ri - (ri-li) / 2;
						int tcnt = 0;
						rep(i2, 10) if (sums[i+1][i2]-sums[ci][i2] > 0) ++tcnt;
						if (tcnt < j) {
							ri = ci;
							continue;
						}
						else if (tcnt > j) {
							li = ci;
							continue;
						}
						int mval = 0;
						rep(i2, 10) mval = max(mval, sums[i+1][i2]-sums[ci][i2]);
						if (mval > tcnt) li = ci;
						else ri = ci;
					}
					res += (i+1) - ri;
				}
				if (j > 1) {
					int li = 0, ri = i;
					while (ri-li > 1) {
						int ci = li + (ri-li) / 2;
						int tcnt = 0;
						rep(i2, 10) if (sums[i+1][i2]-sums[ci][i2] > 0) ++tcnt;
						if (tcnt < j) ri = ci;
						else li = ci;
					}
					res -= (i+1) - ri;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
