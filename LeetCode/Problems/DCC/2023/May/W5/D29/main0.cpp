// 自力AC

#include <bits/stdc++.h>
using namespace std;

class ParkingSystem {
    vector<int> spaces;
public:
    ParkingSystem(int big, int medium, int small) {
        spaces = { big, medium, small };
    }
    bool addCar(int carType) {
        return spaces[--carType]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
