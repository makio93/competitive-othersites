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
		string keys, s;
		cin >> keys >> s;
		unordered_map<char, int> p;
		rep(i, 26) p[keys[i]] = i;
		int n = s.length(), res = 0;
		rep(i, n-1) res += abs(p[s[i]]-p[s[i+1]]);
		cout << res << endl;
	}
	return 0;
}
