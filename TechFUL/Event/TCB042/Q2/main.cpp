#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = (int)(1e9);

int main() {
    vector<int> vals(4);
    for (int i=0; i<4; ++i) cin >> vals[i];
    int mval = INF;
    for (int i=0; i<4; ++i) for (int j=i+1; j<4; ++j) {
        vector<int> sum(2);
        for (int j2=0; j2<4; ++j2) {
            if (j2==i || j2==j) sum[1] += vals[j2];
            else sum[0] += vals[j2];
        }
        mval = min(mval, abs(sum[1]-sum[0]));
    }
    cout << mval << endl;
    return 0;
}
