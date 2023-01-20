// 自力AC

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
	ll m;
	cin >> m;
	string res;
	if (m == 0) {
		res += "a";
		cout << res << endl;
		return 0;
	}
	vector<ll> add;
	ll val = 0;
	rep(i, 10000) {
		val += i+1;
		if (val > m) break;
		add.push_back(val);
	}
	int n = add.size();
	vector<int> ccnt(n);
	while (m > 0) {
		int id = upper_bound(all(add), m) - add.begin();
		ccnt[id-1]++;
		m -= add[id-1];
	}
	rep(i, n) {
		res += "no";
		if (ccnt[i] > 0) res += string(ccnt[i], 'c');
	}
	reverse(all(res));
	cout << res << endl;
	return 0;
}
