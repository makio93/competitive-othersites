#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i=0; i<2*n; ++i) {
        if (s[i] == 'A') ++a;
        else ++b;
    }
    cout << (min(a,n)+min(b,n)) << endl;
    return 0;
}
