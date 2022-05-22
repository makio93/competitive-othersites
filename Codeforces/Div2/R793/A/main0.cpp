// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		int cid = (n-1) / 2;
		int li = cid, ri = cid;
		if (n%2 == 0) ++ri;
		while (li-1>=0 && ri+1<n && s[li-1]==s[cid] && s[ri+1]==s[cid]) {
			--li; ++ri;
		}
		cout << (ri-li+1) << endl;
	}
	return 0;
}
