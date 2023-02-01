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
		int n, k;
		string a, b;
		cin >> n >> k >> a >> b;
		vector<bool> ccnt(26);
		rep(i, n) ccnt[a[i]-'a'] = true;
		vector<char> clst;
		rep(i, 26) if (ccnt[i]) clst.push_back((char)('a'+i));
		int m = clst.size();
		ll res = 0;
		if (m <= k) res = (ll)n * (n+1) / 2;
		else {
			rep(i, 1<<m) if ((int)(__builtin_popcount(i)) == k) {
				vector<char> chs;
				rep(j, m) if (i&(1<<j)) chs.push_back(clst[j]);
				vector<pair<int, int>> rlst;
				rep(j, n) {
					if (a[j]==b[j] || find(all(chs),a[j])!=chs.end()) {
						if (rlst.empty() || rlst.back().second!=j-1) rlst.emplace_back(1, j);
						else {
							rlst.back().first++;
							rlst.back().second = j;
						}
					}
				}
				ll val = 0;
				for (const auto& pi : rlst) val += (ll)pi.first * (pi.first+1) / 2;
				res = max(res, val);
			}
		}
		cout << res << endl;
	}
	return 0;
}
