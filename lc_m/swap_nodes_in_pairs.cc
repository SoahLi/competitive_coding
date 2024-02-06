#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//impliment the recursive solution
ListNode* swapPairs(ListNode* head) {
  if(head -> next == nullptr) return head;
  ListNode* current = head;
  ListNode* next = head->next;
  int temp;

  
  while(next != nullptr) {
    temp = next->val;
    next->val = current->val;
    current->val = temp;

    next = next->next;
    if(next == nullptr) break;
    next = next->next;
    current = current->next->next;
  }

  return head;
}

int main() {
  // ListNode* myListNode = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  ListNode* myListNode = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  ListNode* ans = swapPairs(myListNode);
  while(ans != nullptr) {
    cout << ans -> val << " ";
    ans = ans -> next;
  }
}
