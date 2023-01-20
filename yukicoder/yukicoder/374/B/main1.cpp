// 解説AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
	int q;
	cin >> q;
	set<int> s;
	vector<int> bcnt(30);
	rep(i1, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi;
			cin >> xi;
			if (s.find(xi) != s.end()) continue;
			s.insert(xi);
			rep(i, 30) if (xi&(1<<i)) bcnt[i]++;
		}
		else if (qi == 2) {
			int xi;
			cin >> xi;
			if (s.find(xi) == s.end()) continue;
			s.erase(xi);
			rep(i, 30) if (xi&(1<<i)) bcnt[i]--;
		}
		else {
			int slen = s.size();
			if (slen == 0) cout << -1 << endl;
			else {
				int res = 0;
				rep(i, 30) if (bcnt[i] == slen) res |= 1<<i;
				cout << res << endl;
			}
		}
	}
	return 0;
}
