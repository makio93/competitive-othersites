#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int h, w, c;
    cin >> h >> w >> c;
    cout << ((ll)(max(h,w)*max(h,w)-h*w)*c) << endl;
    return 0;
}
