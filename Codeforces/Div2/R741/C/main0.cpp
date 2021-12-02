#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番終了後,自力AC

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		int rzid = -1, lzid = n;
		rep(i, n) if (s[i] == '0') {
			rzid = max(rzid, i);
			lzid = min(lzid, i);
		}
		int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
		if (rzid!=-1 && rzid>=n/2) { l1 = 1; r1 = rzid+1; l2 = 1; r2 = rzid; }
		else if (lzid!=n && lzid<=(n-1)/2) { l1 = lzid+1; r1 = n; l2 = lzid+2; r2 = n; }
		else { l1 = 1; r1 = n/2; l2 = n-(n/2-1); r2 = n; }
		cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
	}
	return 0;
}
