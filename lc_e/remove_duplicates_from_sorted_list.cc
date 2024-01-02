#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;

    ListNode* unique = new ListNode(head->val);
    ListNode* cursor = unique;

    while(head != nullptr) {
        if(head->val != cursor->val){
            cursor = cursor->next = new ListNode(head->val);
        }
        head = head->next;
    }
    return unique;
}

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    // ListNode* myListNode = new ListNode(1, new ListNode(1, new ListNode(2)));
    // myListNode = deleteDuplicates(myListNode);
    ListNode* myListNode = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(3, new ListNode(3))))));
    myListNode = deleteDuplicates(myListNode);
    printList(myListNode);

} 