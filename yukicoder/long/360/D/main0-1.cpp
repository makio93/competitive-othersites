// 本番WA

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

const string tar = "con";

int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<vector<int>> ccnt(3, vector<int>(3));
	vector<int> bcnt(3);
	rep(i, 3*n) {
		int cid = -1;
		rep(j, 3) if (s[i] == tar[j]) {
			cid = j;
			break;
		}
		if (cid == -1) bcnt[i%3]++;
		else ccnt[i%3][cid]++;
	}
	int cval = 0, cvcnt = 0;
	rep(i, 3) {
		int tval = INF;
		rep(j, 3) tval = min(tval, ccnt[(i+j)%3][j]);
		cval += tval;
		rep(j, 3) ccnt[(i+j)%3][j] -= tval;
		if (tval > 0) ++cvcnt;
	}
	rep(i, 2) rep(j, 3) bcnt[i] += ccnt[i][j];
	if (cvcnt<=1 || (bcnt[0]>0&&bcnt[1]>0)) cout << cval << endl;
	else cout << max(0, cval-1) << endl;
	return 0;
}
