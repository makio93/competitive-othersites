// 学習0回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
	int n, q;
	cin >> n;
	unordered_set<int> s;
	rep(i, n) {
		int si;
		cin >> si;
		s.insert(si);
	}
	cin >> q;
	vector<int> t(q);
	rep(i, q) cin >> t[i];
	int res = 0;
	rep(i, q) if (s.find(t[i]) != s.end()) ++res;
	cout << res << endl;
	return 0;
}
