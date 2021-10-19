#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i=0; i<q; ++i) {
        int qi;
        cin >> qi;
        --qi;
        cout << s[qi] << endl;
    }
    return 0;
}
