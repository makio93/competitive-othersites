// 

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
	int q0;
	cin >> q0;
	rep(i0, q0) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		if (s[0]!=t[0] || s[n-1]!=t[n-1]) {
			cout << -1 << endl;
			continue;
		}
		auto sl_make = [](string str) -> vector<pair<int, int>> {
			int len = str.length();
			vector<pair<int, int>> lst;
			rep(i, len) if (str[i] == '1') {
				if (i-1<0 || str[i-1]=='0') lst.emplace_back(i, -1);
				if (i+1>=len || str[i+1]=='0') lst.back().second = i;
			}
			return lst;
		};
		auto slst = sl_make(s), tlst = sl_make(t);
		if (slst.size() != tlst.size()) {
			cout << -1 << endl;
			continue;
		}
		int m = slst.size();
		ll res = 0;
		rep(i, m) res += abs(slst[i].first-tlst[i].first) + abs(slst[i].second-tlst[i].second);
		cout << res << endl;
	}
	return 0;
}
