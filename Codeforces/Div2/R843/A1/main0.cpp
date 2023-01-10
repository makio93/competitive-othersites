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
		string s;
		cin >> s;
		int n = s.length();
		vector<pair<char, int>> clst;
		clst.emplace_back(s[0], 1);
		rep3(i, 1, n) {
			if (clst.back().first == s[i]) clst.back().second++;
			else clst.emplace_back(s[i], 1);
		}
		string res;
		int m = clst.size();
		if (m >= 3) {
			rep(i, 2) res += string(clst[i].second, clst[i].first) + " ";
			rep3(i, 2, m) res += string(clst[i].second, clst[i].first);
		}
		else if (m == 1) {
			rep(i, 2) res += string(1, clst[0].first) + " ";
			res += string(clst[0].second-2, clst[0].first);
		}
		else {
			if (clst[0].second <= clst[1].second) {
				res += string(clst[0].second, clst[0].first) + " ";
				if (clst[0].first < clst[1].first) {
					res += string(clst[1].second-1, clst[1].first) + " ";
					res += string(1, clst[1].first);
				}
				else {
					res += string(1, clst[1].first) + " ";
					res += string(clst[1].second-1, clst[1].first);
				}
			}
			else {
				if (clst[0].first < clst[1].first) {
					res += string(clst[0].second-1, clst[0].first) + " ";
					res += string(1, clst[0].first) + " ";
				}
				else {
					res += string(1, clst[0].first) + " ";
					res += string(clst[0].second-1, clst[0].first) + " ";
				}
				res += string(clst[1].second, clst[1].first);
			}
		}
		cout << res << endl;
	}
	return 0;
}
