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
		int n, m;
		cin >> n >> m;
		vector<vector<bool>> board(n, vector<bool>(n));
		rep(i, m) {
			int xi, yi;
			cin >> xi >> yi;
			--xi; --yi;
			board[xi][yi] = true;
		}
		auto check = [&n](vector<vector<bool>>& b) -> bool {
			rep(i, n) {
				int cnt = 0;
				rep(j, n) if (b[i][j]) ++cnt;
				if (cnt >= 2) return false;
				cnt = 0;
				rep(j, n) if (b[j][i]) ++cnt;
				if (cnt >= 2) return false;
			}
			return true;
		};
		bool res = false;
		rep(i, n) {
			rep(j, n) if (board[i][j]) {
				int xi = i, yi = j;
				board[i][j] = false;
				--xi;
				while (xi>=0 && !board[xi][j]) {
					board[xi][j] = true;
					if (check(board)) {
						res = true;
						break;
					}
					board[xi][j] = false;
					--xi;
				}
				if (res) break;
				xi = i;
				++xi;
				while (xi<n && !board[xi][j]) {
					board[xi][j] = true;
					if (check(board)) {
						res = true;
						break;
					}
					board[xi][j] = false;
					++xi;
				}
				if (res) break;
				xi = i;
				--yi;
				while (yi>=0 && !board[i][yi]) {
					board[i][yi] = true;
					if (check(board)) {
						res = true;
						break;
					}
					board[i][yi] = false;
					--yi;
				}
				if (res) break;
				yi = j;
				++yi;
				while (yi<n && !board[i][yi]) {
					board[i][yi] = true;
					if (check(board)) {
						res = true;
						break;
					}
					board[i][yi] = false;
					++yi;
				}
				if (res) break;
				board[i][j] = true;
			}
			if (res) break;
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
