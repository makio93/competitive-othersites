#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const string s1 = "()", s2 = "(())", t2 = "()()";

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		string tar;
		rep(i, n) tar += s1;
		cout << tar << endl;
		rep(i, n-1) {
			rep(j, 4) tar[i*2+j] = s2[j];
			cout << tar << endl;
			rep(j, 4) tar[i*2+j] = t2[j];
		}
	}
	return 0;
}
