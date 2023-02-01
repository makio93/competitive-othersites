#include <bits/stdc++.h>
using namespace std;

// 自力AC

const vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };
const vector<string> dir = { "East", "North", "West", "South" };
class Robot {
    int h, w, y, x, d, roop;
    bool fir;
public:
    Robot(int width, int height) {
        h = height; w = width;
        y = 0; x = 0; d = 0;
        roop = (h-1) * 2 + (w-1) * 2;
        fir = true;
    }
    void move(int num) {
        if (num >= roop) {
            num = num % roop;
            if (fir) d = (d + 3) % 4;
            if ((y==0||y==h-1) && (x==0||x==w-1)) {
                if (num > 0) d = (d+1) % 4;
            }
        }
        fir = false;
        while (num > 0) {
            int ny = max(0, min(h-1, y+dy[d]*num)), nx = max(0, min(w-1, x+dx[d]*num));
            int sub = abs(ny-y) + abs(nx-x);
            y = ny; x = nx;
            num -= sub;
            if (num > 0) d = (d+1) % 4;
        }
    }
    vector<int> getPos() {
        vector<int> res = { x, y };
        return res;
    }
    string getDir() {
        return dir[d];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
