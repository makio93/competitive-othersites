#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size(), cnt = 0;
        for (int i=0; i<m; ++i) if (flowerbed[i] == 0) {
            if ((i-1<0||flowerbed[i-1]==0) && (i+1>=m||flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                ++cnt;
            }
        }
        return (cnt >= n);
    }
};
