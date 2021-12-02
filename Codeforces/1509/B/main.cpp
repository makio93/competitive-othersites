#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int t;
	cin >> t;
	rep(i1, t) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int mcnt = 0;
		rep(i, n) if (s[i] == 'M') ++mcnt;
		if (mcnt != n/3) {
			cout << "NO" << endl;
			continue;
		}
		vector<vector<int>> lsum(2, vector<int>(n+1)), rsum(2, vector<int>(n+1));
		bool ok = true;
		rep(i, n) {
			lsum[0][i+1] = lsum[0][i] + (s[i]=='T'?1:0);
			lsum[1][i+1] = lsum[1][i] + (s[i]=='M'?1:0);
			if (lsum[0][i+1]<lsum[1][i+1]) ok = false;
		}
		repr(i, n) {
			rsum[0][i] = rsum[0][i+1] + (s[i]=='T'?1:0);
			rsum[1][i] = rsum[1][i+1] + (s[i]=='M'?1:0);
			if (rsum[0][i]<rsum[1][i]) ok = false;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

