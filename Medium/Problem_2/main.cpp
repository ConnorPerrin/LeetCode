#include <iostream>
#include "linkedList.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        int carry = 0;
        int sum = 0;

        int l1_val = 0;
        int l2_val = 0;

        while(l1 || l2) {
            l1_val = (!l1) ? 0 : l1->val;
            l2_val = (!l2) ? 0 : l2->val;

            sum = l1_val + l2_val;

            ListNode* newNode = new ListNode((sum + carry) % 10);
            carry = ((sum + carry) > 9) ? 1 : 0;

            current->next = newNode;
            current = current->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(1);
            current->next = newNode;
        }

        return head->next;
    }
};

int main(){
    std::cout << "LeetCode Problem 2 - Add Two Numbers" << std::endl;
    Solution s;

    ListNode* l1 = stringToListNode("[9,9,9,9]");
    ListNode* l2 = stringToListNode("[9,9]");
    ListNode* answer = s.addTwoNumbers(l1, l2);
    prettyPrintLinkedList(answer);

    return 0;
}