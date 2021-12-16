#include <iostream>
#include "linkedList.hpp"

class Solution {
public:
    void insert(ListNode* head, ListNode* node) {
        while(head->next && (head->next->val < node->val)) {
            head = head->next;
        }

        node->next = head->next;
        head->next = node;
    }

    ListNode* insertionSortList(ListNode* head) {
        if(!head) return nullptr;

        ListNode* sortedHead = new ListNode(0);

        while(head) {
            ListNode* node = head;
            head = head->next;
            insert(sortedHead, node);
        }
       
        return sortedHead->next;
    }
};

int main(){
    std::cout << "LeetCode 147 - Insertion Sort List" << std::endl;
    Solution s;

    ListNode* head = stringToListNode("[4,3,2,1]");
    ListNode* answer = s.insertionSortList(head);
    prettyPrintLinkedList(answer);

    return 0;
}