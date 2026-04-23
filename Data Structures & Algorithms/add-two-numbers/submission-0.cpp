/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int headNumber = 0;
        ListNode* temp;
        while(l1&&l2){
            temp = l1;
            int total = l1->val + l2->val + carry;
            carry = total/10;
            total = total%10;
            l1->val = total;
            l2->val = total;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            temp = l1;
            int total = l1->val + carry;
            carry = total/10;
            total = total%10;
            l1->val = total;
            l1 = l1->next;
        }

        while(l2){
            temp = l2;
            int total = l2->val + carry;
            carry = total/10;
            total = total%10;
            l2->val = total;
            l2 = l2->next;
            headNumber = 1;
        }

        if(carry){
            temp->next = new ListNode(carry);
        }

        return headNumber==1?head2:head1;
    }
};
