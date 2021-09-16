#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int h, s;
    cin >> h >> s;
    int di = round(sqrt(2*h/9.80) * s * 100);
    printf("%.2f\n", (double)(di/100.0));
    return 0;
}
