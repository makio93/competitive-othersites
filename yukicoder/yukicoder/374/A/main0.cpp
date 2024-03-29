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
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> res;
	if (c<=b && c%a==0) res.push_back(c/a);
	if ((c+b)%a == 0) res.push_back((c+b)/a);
	if (res.empty()) cout << -1 << endl;
	else for (const int& val : res) cout << val << endl;
	return 0;
}
