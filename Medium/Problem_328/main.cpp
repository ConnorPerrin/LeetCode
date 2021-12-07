#include <iostream>
#include "linkedList.hpp"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;

        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* evenStartNode = head->next;

        while(oddNode->next && evenNode->next) {
            oddNode->next = evenNode->next;
            evenNode->next = evenNode->next->next;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }

        oddNode->next = evenStartNode;

        return head;  
    }
};

int main(){
    std::cout << "LeetCode 328 - Odd Even Linked List" << std::endl;
    Solution s;

    ListNode* head = stringToListNode("[4,3,2,1]");
    ListNode* answer = s.oddEvenList(head);
    prettyPrintLinkedList(answer);


    return 0;
}