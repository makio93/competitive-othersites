#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int mlen = 0, wcnt = 0, wsum = 0;
    for (char c : s) {
        if (c != 'w') wcnt = 0;
        else {
            ++wcnt;
            ++wsum;
            mlen = max(mlen, wcnt);
        }
    }
    cout << (mlen+wsum) << endl;
    return 0;
}
