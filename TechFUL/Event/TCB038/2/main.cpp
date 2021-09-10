#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x > 0) cout << (x*2) << endl;
    else if (x < 0) cout << ((-x)*2+1) << endl;
    else cout << 1 << endl;
    return 0;
}
