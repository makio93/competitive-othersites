// 本番終了後,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class LightbulbRow {
public:
    string solve(string bulbStates, int startIndex, int goalCount) {
        int n = bulbStates.length(), bcnt = 0;
        rep(i, n) if (bulbStates[i] == 'O') ++bcnt;
        bool on = (bcnt < goalCount);
        string res;
        if (bcnt != goalCount) {
            int id = startIndex;
            bool right = true;
            while (1) {
                if (on) {
                    if (bulbStates[id] == 'X') {
                        res += 'S';
                        ++bcnt;
                        bulbStates[id] = 'O';
                    }
                }
                else {
                    if (bulbStates[id] == 'O') {
                        res += 'S';
                        --bcnt;
                        bulbStates[id] = 'X';
                    }
                }
                if (bcnt == goalCount) break;
                if (right) {
                    if (id+1 <= n-1) {
                        ++id;
                        res += '>';
                    }
                    else {
                        right = false;
                        --id;
                        res += '<';
                    }
                }
                else {
                    if (id-1 >= 0) {
                        --id;
                        res += '<';
                    }
                    else {
                        right = true;
                        ++id;
                        res += '>';
                    }
                }
            }
        }
        return res;
    }
};
