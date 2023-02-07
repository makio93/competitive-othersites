// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return (int)ceil(log(buckets)/log(minutesToTest/minutesToDie+1));
    }
};
