// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        int m = flowerbed.size();
        for (int i=0; i<m; ++i) {
            if (flowerbed[i]==0 && (i-1<0 || flowerbed[i-1]==0) && (i+1>=m || flowerbed[i+1]==0)) {
                --n;
                flowerbed[i] = 1;
                if (n == 0) return true;
            }
        }
        return false;
    }
};
