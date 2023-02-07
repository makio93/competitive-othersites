#include <bits/stdc++.h>
using namespace std;

// 自力AC

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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */