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
		string s;
		cin >> s;
		int n = s.length();
		vector<int> vals(n);
		int sum = 0;
		rep(i, n) {
			if (s[i] == '(') vals[i] = 1;
			else if (s[i] == ')') vals[i] = -1;
			else vals[i] = 1;
			sum += vals[i];
		}
		repr(i, n) {
			if (sum == 0) break;
			if (s[i] == '?') {
				vals[i] = -1;
				sum -= 2;
			}
		}
		vector<int> lsum(n+1);
		rep(i, n) lsum[i+1] = lsum[i] + vals[i];
		int mval = 0;
		bool ok = true, search = false;
		rep(i, n) {
			if (s[i]=='?' && vals[i]==1 && !search) {
				search = true;
				mval = lsum[i+1];
			}
			else if (s[i]=='?' && vals[i]==-1 && search) {
				if (mval >= 2) {
					ok = false;
					break;
				}
				search = false;
			}
			else if (s[i]=='?' && vals[i]==1 && search) mval = max(mval, lsum[i+1]);
			else mval = min(mval, lsum[i+1]);
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
