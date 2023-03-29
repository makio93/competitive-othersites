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
		int l, r;
		cin >> l >> r;
		pair<int, int> mval = { -1, -1 };
		auto calc = [](int val) -> int {
			int li = 10, ri = -1;
			while (val > 0) {
				li = min(li, val%10);
				ri = max(ri, val%10);
				val /= 10;
			}
			return max(0, ri-li);
		};
		rep3(i, l, r+1) {
			mval = max(mval, { calc(i), i });
			if (mval.first >= 9) break;
		}
		cout << mval.second << endl;
	}
	return 0;
}
