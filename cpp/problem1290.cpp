// Solution for Problem 1290. Convert Binary Number in a Linked List to Integer
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head) {
    string store = "";
    while (head) {
        store.push_back('0' + head->val);
        head = head->next;
    }
    return stoi(store, nullptr, 2);
}

ListNode* createList(int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    while (n--) {
        int x; cin >> x;
        ListNode* node = new ListNode(x);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main() {
    int n; cin >> n;
    ListNode* list = createList(n);
    cout << getDecimalValue(list);
}