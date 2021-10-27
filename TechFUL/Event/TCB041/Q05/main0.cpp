// 本番AC

#include <iostream>
using namespace std;

int main() {
    int q, k;
    cin >> q >> k;
    for (int i=0; i<q; ++i) {
        int ni, mi;
        cin >> ni >> mi;
        bool res = false;
        while (ni>0 && mi>0) {
            if (ni%k+mi%k >= k) {
                res = true;
                break;
            }
            ni /= k; mi /= k;
        }
        if (res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
