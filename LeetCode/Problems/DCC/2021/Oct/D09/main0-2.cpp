#include <bits/stdc++.h>
using namespace std;

// 自力TLE,2

class Solution {
    class Trie {
        struct Node {
            char c;
            bool fin;
            unordered_map<char, Node*> nextNodes;
            Node() : c('*'), fin(false), nextNodes() {}
            Node(char c) : c(c), fin(false), nextNodes() {}
            Node* nextNode(char t) {
                if (nextNodes.find(t) != nextNodes.end()) return nextNodes[t];
                else return (nextNodes[t] = new Node(t));
            }
            Node* searchNode(char t) {
                if (nextNodes.find(t) != nextNodes.end()) return nextNodes[t];
                else return NULL;
            }
        };
        Node *head;
    public:
        Trie() { head = new Node(); }
        void insert(string word) {
            auto p = head;
            for (char ci : word) p = p->nextNode(ci);
            p->fin = true;
        }
        bool search(string word) {
            auto p = head;
            for (char ci : word) {
                p = p->searchNode(ci);
                if (p == NULL) return false;
            }
            return p->fin;
        }
        bool startsWith(string prefix) {
            auto p = head;
            for (char ci : prefix) {
                p = p->searchNode(ci);
                if (p == NULL) return false;
            }
            return true;
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board.front().size(), wl = words.size();
        Trie tr;
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
            vector<vector<bool>> visited(m, vector<bool>(n));
            function<void(int,int,string&)> dfs = [&](int y, int x, string& str) {
                if (str.length() >= 10) {
                    tr.insert(str);
                    return;
                }
                visited[y][x] = true;
                bool proc = false;
                const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
                for (int i2=0; i2<4; ++i2) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=m || nx<0 || nx>=n) continue;
                    if (visited[ny][nx]) continue;
                    str.push_back(board[ny][nx]);
                    dfs(ny, nx, str);
                    str.pop_back();
                    proc = true;
                }
                if (!proc) tr.insert(str);
                visited[y][x] = false;
            };
            string si = string(1, board[i][j]);
            dfs(i, j, si);
        }
        vector<string> res;
        for (int i=0; i<wl; ++i) if (tr.startsWith(words[i])) res.push_back(words[i]);
        return res;
    }
};
