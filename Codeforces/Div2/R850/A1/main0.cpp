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
		bool alice = true;
		int aval = 0, bval = 0, id = 0;
		while (n > 0) {
			if (id%2 == 1) alice = !alice;
			if (alice) aval += min(id+1, n);
			else bval += min(id+1, n);
			n -= min(id+1, n);
			++id;
		}
		cout << aval << ' ' << bval << endl;
	}
	return 0;
}
