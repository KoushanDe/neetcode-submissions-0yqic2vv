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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* node = dummy;
        ListNode* prev = NULL;

        int step = 1;
        while(curr!=NULL){
            curr = curr->next;
            step++;
            if(step>n){
                prev = node;
                node = node->next;
            }
        }
        
        prev->next = node->next;

        return dummy->next;

    }
};
