#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m <= n) cout << ": )" << endl;
    else cout << (m-n) << endl;
    return 0;
}
