#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        bool ok = true;
        for (char c : text) {
            if (c == ' ') {
                if (ok) ++res;
                ok = true;
            }
            else {
                if (ok) {
                    for (char c2 : brokenLetters) if (c2 == c) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) ++res;
        return res;
    }
};

int main() {

    return 0;
}
