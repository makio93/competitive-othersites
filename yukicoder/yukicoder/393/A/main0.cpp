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
	int x;
	cin >> x;
	if (x>=3 && x<=5) cout << "spring" << endl;
	else if (x>=6 && x<=8) cout << "summer" << endl;
	else if (x>=9 && x<=11) cout << "fall" << endl;
	else cout << "winter" << endl;
	return 0;
}
