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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		if (n <= 3) {
			cout << "NO" << endl;
			continue;
		}
		vector<vector<int>> vcnt(2, vector<int>(26*26));
		vcnt[1][(s[0]-'a')*26+(s[1]-'a')]++;
		vcnt[2%2] = vcnt[1];
		vcnt[2%2][(s[1]-'a')*26+(s[2]-'a')]++;
		bool ok = false;
		rep3(i, 3, n) {
			int val = (s[i-1]-'a') * 26 + (s[i]-'a');
			if (vcnt[(i-2)%2][val] >= 1) {
				ok = true;
				break;
			}
			vcnt[i%2] = vcnt[(i-1)%2];
			vcnt[i%2][val]++;
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
