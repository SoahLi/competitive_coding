#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Submission 1: Runtime Error
// ListNode* reverseList(ListNode* head) {
//     vector<ListNode*> nodes;
//     ListNode* cursor = head;

//     while(cursor != nullptr){
//         nodes.push_back(cursor);
//         cursor = cursor -> next;
//     }

//     ListNode* reversed = nodes.back();
//     cursor = reversed;
//     nodes.pop_back();

//     for(int i=nodes.size()-1; i>=0; i--) {
//         cursor -> next = nodes[i];
//         cursor = cursor -> next;
//     }

//     cursor -> next = nullptr;
//     return reversed;
// }

//Submission 2: PASSING
/*
 * Time Complexity: O(n)
 * Space Complexity: O(n) -> O(1) can be achieved
*/
ListNode* reverseList(ListNode* head) {
    if(head == nullptr) return nullptr;

    vector<ListNode*> nodes;
    ListNode* cursor = head;

    while(cursor != nullptr){
        nodes.push_back(cursor);
        cursor = cursor -> next;
    }

    ListNode* reversed = nodes.back();
    cursor = reversed;
    nodes.pop_back();

    for(int i=nodes.size()-1; i>=0; i--) {
        cursor -> next = nodes[i];
        cursor = cursor -> next;
    }

    cursor -> next = nullptr;
    return reversed;
}

int main() {
    // ListNode* myList = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    // ListNode* myList = new ListNode(1, new ListNode(2));
    ListNode* myList = new ListNode();
    ListNode* reversed = reverseList(myList);
    while(reversed != nullptr){
        cout << (reversed -> val) << '\n';
        reversed = reversed -> next;
    }
}