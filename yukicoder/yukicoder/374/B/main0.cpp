// 本番AC

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
	vector<int> zcnt(30);
	rep(i1, q) {
		int qi;
		cin >> qi;
		if (qi == 1) {
			int xi;
			cin >> xi;
			if (s.find(xi) != s.end()) continue;
			s.insert(xi);
			rep(i, 30) if (!(xi&(1<<i))) zcnt[i]++;
		}
		else if (qi == 2) {
			int xi;
			cin >> xi;
			if (s.find(xi) == s.end()) continue;
			s.erase(xi);
			rep(i, 30) if (!(xi&(1<<i))) zcnt[i]--;
		}
		else {
			if (s.empty()) cout << -1 << endl;
			else {
				int res = 0;
				rep(i, 30) if (zcnt[i] == 0) res |= 1<<i;
				cout << res << endl;
			}
		}
	}
	return 0;
}
