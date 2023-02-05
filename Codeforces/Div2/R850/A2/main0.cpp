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
		int n;
		cin >> n;
		bool alice = true, white = true;
		int id = 0, aw = 0, ab = 0, bw = 0, bb = 0;
		while (n > 0) {
			if (id%2 == 1) alice = !alice;
			if (alice) {
				if (white) {
					aw += (min(n, id+1) + 1) / 2;
					ab += min(n, id+1) / 2;
				}
				else {
					ab += (min(n, id+1) + 1) / 2;
					aw += min(n, id+1) / 2;
				}
			}
			else {
				if (white) {
					bw += (min(n, id+1) + 1) / 2;
					bb += min(n, id+1) / 2;
				}
				else {
					bb += (min(n, id+1) + 1) / 2;
					bw += min(n, id+1) / 2;
				}
			}
			n -= min(n, id+1);
			if ((id+1)%2 == 1) white = !white;
			++id;
		}
		cout << aw << ' ' << ab << ' ' << bw << ' ' << bb << endl;
	}
	return 0;
}
