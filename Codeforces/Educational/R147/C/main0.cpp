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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		string s;
		cin >> s;
		int n = s.length();
		int res = INF;
		rep(i, 26) {
			vector<int> rlst;
			rep(j, n) {
				if (s[j] == (char)('a'+i)) continue;
				if (j-1<0 || s[j-1]==(char)('a'+i)) rlst.push_back(1);
				else rlst.back()++;
			}
			int val = 0, m = rlst.size();
			rep(j, m) {
				int tmp = rlst[j], cnt = 0;
				while (tmp > 0) {
					tmp /= 2;
					++cnt;
				}
				val = max(val, cnt);
			}
			res = min(res, val);
		}
		cout << res << endl;
	}
	return 0;
}
