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
	ll m;
	cin >> m;
	vector<int> cvals;
	rep(i, 3) {
		if (i < 2) cvals.push_back(m%10000);
		else cvals.push_back((int)m);
		m /= 10000;
	}
	reverse(all(cvals));
	string res = string(cvals[0], 'c') + string(10000, 'o') + string(9998, 'n');
	res += string(cvals[1], 'c') + string(9999, 'o') + string(cvals[2], 'c') + string("on");
	cout << res << endl;
	return 0;
}
