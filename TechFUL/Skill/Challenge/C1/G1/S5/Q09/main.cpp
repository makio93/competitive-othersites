#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll v, k, t;
    cin >> v >> k >> t;
    if (k*t>=v/10*8 && k*t<=v) cout << "Yatta!" << endl;
    else if (k*t < v/10*8) cout << "Oh..." << endl;
    else cout << "Overflow" << endl;
    return 0;
}
