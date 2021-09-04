#include <bits/stdc++.h>
using namespace std;

// 自力WA

class Solution {
    const int INF = (int)(1e4);
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        vector<map<int, int>> xy(2);
        for (int i=0; i<n; ++i) for (int j=0; j<2; ++j) {
            if (xy[j].find(trees[i][0]) == xy[j].end()) xy[j][trees[i][0]] = trees[i][1];
            else {
                if (j == 0) xy[j][trees[i][0]] = max(xy[j][trees[i][0]], trees[i][1]);
                else xy[j][trees[i][0]] = min(xy[j][trees[i][0]], trees[i][1]);
            }
        }
        set<pair<int, int>> choosed;
        for (int i1=0; i1<2; ++i1) {
            pair<int, int> rpos = { xy[i1].begin()->first, xy[i1].begin()->second }, tfrac = { 1, -INF }, tpos = { -1, -1 };
            if (i1 == 1) tfrac.second *= -1;
            choosed.insert(rpos);
            set<pair<int, int>> ins;
            vector<int> ops = { 1, -1 };
            for (auto p : xy[i1]) if (rpos.first != p.first) {
                auto fcalc = [](pair<int, int> ri, pair<int, int> ti) -> pair<int, int> {
                    if (abs(ti.second-ri.second) > 0) {
                        int gi = gcd(ti.first-ri.first, abs(ti.second-ri.second));
                        return { (ti.first-ri.first)/gi, (ti.second-ri.second)/gi };
                    }
                    else return { ti.first-ri.first, 0 };
                };
                auto fcomp = [](pair<int, int> fs, pair<int, int> ft, int op) -> bool {
                    int li = lcm(fs.first, ft.first);
                    if (op == 0) return (ft.second*(li/ft.first) == fs.second*(li/fs.first));
                    else if (op > 0) return (ft.second*(li/ft.first) > fs.second*(li/fs.first));
                    else return (ft.second*(li/ft.first) < fs.second*(li/fs.first));
                };
                int nx = p.first, ny = p.second;
                pair<int, int> nfrac = fcalc(rpos, {nx,ny});
                if (fcomp(tfrac, nfrac, 0)) ins.insert(tpos);
                else if (fcomp(tfrac, nfrac, ops[i1])) ins.clear();
                else {
                    ins.insert(tpos);
                    for (auto p : ins) choosed.insert(p);
                    ins.clear();
                    rpos = tpos;
                }
                tpos = { nx, ny };
                tfrac = fcalc(rpos, tpos);
                if (nx == xy[i1].rbegin()->first) {
                    ins.insert(tpos);
                    for (auto p : ins) choosed.insert(p);
                }
            }
        }
        int lid = xy.front().begin()->first, rid = xy.front().rbegin()->first;
        for (int i=0; i<n; ++i) if (trees[i][0]==lid || trees[i][0]==rid) choosed.emplace(trees[i][0], trees[i][1]);
        vector<vector<int>> res;
        for (auto p : choosed) res.push_back({ p.first, p.second });
        return res;
    }
};
