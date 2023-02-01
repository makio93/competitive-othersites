#include <bits/stdc++.h>
using namespace std;

// 本番AC

class DetectSquares {
    vector<unordered_map<int, int>> ytox, xtoy;
public:
    DetectSquares() {
        ytox = vector<unordered_map<int, int>>(1001);
        xtoy = vector<unordered_map<int, int>>(1001);
    }
    
    void add(vector<int> point) {
        ytox[point[1]][point[0]]++;
        xtoy[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        if (!xtoy[point[0]].empty()) {
            for (auto xpi : ytox[point[1]]) if (xpi.first != point[0]) {
                int dx = abs(xpi.first - point[0]);
                if (xtoy[point[0]].find(point[1]+dx)!=xtoy[point[0]].end() && ytox[point[1]+dx].find(xpi.first)!=ytox[point[1]+dx].end()) {
                    res += xpi.second * xtoy[point[0]][point[1]+dx] * ytox[point[1]+dx][xpi.first];
                }
                if (point[1]-dx>=0 && xtoy[point[0]].find(point[1]-dx)!=xtoy[point[0]].end() && ytox[point[1]-dx].find(xpi.first)!=ytox[point[1]-dx].end()) {
                    res += xpi.second * xtoy[point[0]][point[1]-dx] * ytox[point[1]-dx][xpi.first];
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
