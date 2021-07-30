#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 自力AC

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        map<Node*, int> pid, qid;
        map<int, Node*> pptr, qptr;
        Node* res = new Node(head->val);
        auto p = head, q = res;
        pid[p] = (int)(pid.size());
        qid[q] = pid[p];
        pptr[pid[p]] = p;
        qptr[qid[q]] = q;
        while (p != NULL) {
            if (pid.find(p) == pid.end()) {
                pid[p] = (int)(pid.size());
                qid[q] = pid[p];
                pptr[pid[p]] = p;
                qptr[qid[q]] = q;
            }
            if (p->random != NULL) {
                if (pid.find(p->random) == pid.end()) {
                    q->random = new Node(p->random->val);
                    pid[p->random] = (int)(pid.size());
                    qid[q->random] = pid[p->random];
                    pptr[pid[p->random]] = p->random;
                    qptr[qid[q->random]] = q->random;
                }
                else q->random = qptr[pid[p->random]];
            }
            if (p->next != NULL) {
                if (pid.find(p->next) == pid.end()) {
                    q->next = new Node(p->next->val);
                    pid[p->next] = (int)(pid.size());
                    qid[q->next] = pid[p->next];
                    pptr[pid[p->next]] = p->next;
                    qptr[qid[q->next]] = q->next;
                }
                else q->next = qptr[pid[p->next]];
            }
            p = p->next;
            q = q->next;
        }
        return res;
    }
};
