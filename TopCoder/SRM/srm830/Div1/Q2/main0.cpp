// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class MorseCodeCorrector {
    const vector<string> tar = {
        ".-",
        "-...",
        "-.-.",
        "-..",
        ".",
        "..-.",
        "--.",
        "....",
        "..",
        ".---",
        "-.-",
        ".-..",
        "--",
        "-.",
        "---",
        ".--.",
        "--.-",
        ".-.",
        "...",
        "-",
        "..-",
        "...-",
        ".--",
        "-..-",
        "-.--",
        "--.."
    };
    const int INF = (int)(1e9);
public:
    string fix(string message) {
        int n = message.length();
        vector<vector<tuple<int, int, int>>> dp(n+1, vector<tuple<int, int, int>>(3, make_tuple(INF, -1, -1 )));
        dp[0][2] = make_tuple(0, -1, -1);
        rep(i, n) {
            rep(j, 26) if (i+1 >= (int)(tar[j].length())) {
                int tcnt = 0, m = tar[j].length();
                rep(j2, m) if (message[i+1-m+j2] != tar[j][j2]) ++tcnt;
                rep3(j2, 1, 3) if (get<0>(dp[i+1-m][j2]) != INF) {
                    dp[i+1][0] = min(dp[i+1][0], make_tuple(get<0>(dp[i+1-m][j2])+tcnt, j2, j ));
                }
            }
            int tcnt1 = (message[i] == '|') ? 0 : 1;
            if (get<0>(dp[i][0]) != INF) dp[i+1][1] = min(dp[i+1][1], make_tuple(get<0>(dp[i][0])+tcnt1, 0, -1));
            if (get<0>(dp[i][1]) != INF) dp[i+1][2] = min(dp[i+1][2], make_tuple(get<0>(dp[i][1])+tcnt1, 1, -1));
        }
        int nj = 0, id = n;
        while (id > 0) {
            if (nj == 0) {
                int ci = get<2>(dp[id][nj]), m = tar[ci].length();
                rep(i2, m) message[id-m+i2] = tar[ci][i2];
                nj = get<1>(dp[id][nj]);
                id -= m;
            }
            else if (nj == 1) {
                message[id-1] = '|';
                nj = get<1>(dp[id][nj]);
                id -= 1;
            }
            else {
                rep(i2, 2) message[id-2+i2] = '|';
                nj = get<1>(dp[id][nj]);
                id -= 1;
            }
        }
        return message;
    }
};
