// 学習1回目,解説AC1-1

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    stack<char> left, right;
public:
    TextEditor() {}
    void addText(string text) { for (const char& ci : text) left.push(ci); }
    int deleteText(int k) {
        int kcnt = 0;
        while (k>0 && !left.empty()) {
            left.pop();
            --k; ++kcnt;
        }
        return kcnt;
    }
    string leftDisplay() {
        string str;
        for (int i=0; i<10; ++i) {
            if (left.empty()) break;
            str.push_back(left.top());
            left.pop();
        }
        reverse(str.begin(), str.end());
        for (const char& ci : str) left.push(ci);
        return str;
    }
    string cursorLeft(int k) {
        while (k>0 && !left.empty()) {
            right.push(left.top());
            left.pop();
            --k;
        }
        return leftDisplay();
    }
    string cursorRight(int k) {
        while (k>0 && !right.empty()) {
            left.push(right.top());
            right.pop();
            --k;
        }
        return leftDisplay();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */