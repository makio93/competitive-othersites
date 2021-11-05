#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> cnt(10);
	for (int i=n-1; i>=0; i-=3) {
		string s1 = s.substr(max(0,i-2), i-max(0,i-2)+1);
		int m = s1.length(), val = 0;
		rep(j, m) {
			val *= 16;
			val += 10 + (int)(s1[j]-'A');
		}
		while (val > 0) {
			cnt[val%8]++;
			val /= 8;
		}
	}
	int mval = 0;
	rep(i, 10) mval = max(mval, cnt[i]);
	vector<int> res;
	rep(i, 10) if (cnt[i] == mval) res.push_back(i);
	int m = res.size();
	rep(i, m) printf("%d%c", res[i], (i<m-1?' ':'\n'));
	return 0;
}
