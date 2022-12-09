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
	int n;
	cin >> n;
	unordered_map<string, int> sc;
	rep(i, n) {
		string si;
		int ci;
		cin >> si >> ci;
		sc[si] = ci;
	}
	vector<int> ccnt(8);
	for (const auto& pi : sc) ccnt[pi.second]++;
	rep(i, 8) cout << ccnt[i] << endl;
	return 0;
}
