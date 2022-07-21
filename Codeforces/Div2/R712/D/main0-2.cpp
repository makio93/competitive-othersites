// 自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    vector<int> rcnt(2, n*n/2);
    if (n*n%2 == 1) rcnt[0]++;
    rep(i1, n*n) {
        int ai;
        cin >> ai;
        int bi = -1, tar = -1, ival = -1, jval = -1;
        if (ai == 1) {
            if (rcnt[1] > 0) {
                bi = 2;
                tar = 1;
            }
            else {
                bi = 3;
                tar = 0;
            }
        }
        else if (ai == 2) {
            if (rcnt[0] > 0) {
                bi = 1;
                tar = 0;
            }
            else {
                bi = 3;
                tar = 1;
            }
        }
        else {
            if (rcnt[0] > 0) {
                bi = 1;
                tar = 0;
            }
            else {
                bi = 2;
                tar = 1;
            }
        }
        rep(i, n) {
            rep(j, n) if ((i+j)%2==tar && board[i][j]==0) {
                board[i][j] = bi;
                rcnt[tar]--;
                ival = i+1;
                jval = j+1;
                break;
            }
            if (ival != -1) break;
        }
        cout << bi << ' ' << ival << ' ' << jval << endl;
        cout.flush();
    }
    return 0;
}
