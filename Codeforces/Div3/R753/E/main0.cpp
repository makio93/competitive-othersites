#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		int slen = s.length();
		int li = 0, ri = 0, ui = 0, di = 0;
		int y = 0, x = 0;
		const string op = "LRDU";
		const vector<int> dy = { 0, 0, 1, -1 }, dx = { -1, 1, 0, 0 };
		rep(i, slen) {
			rep(j, 4) if (s[i] == op[j]) {
				y += dy[j]; x += dx[j];
				break;
			}
			int nli = min(li, x), nri = max(ri, x), nui = min(ui, y), ndi = max(di, y);
			if (nri-nli+1<=m && ndi-nui+1<=n) {
				li = nli; ri = nri; ui = nui; di = ndi;
			}
			else break;
		}
		int ry = n - di, rx = m - ri;
		cout << ry << ' ' << rx << endl;
	}
	return 0;
}
