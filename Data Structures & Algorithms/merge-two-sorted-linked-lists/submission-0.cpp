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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1;
        ListNode* l2;
        ListNode* temp;
        ListNode* result;

        if(!list1) return list2;
        if(!list2) return list1;

        if(list1->val<=list2->val){
            l1=list1;
            l2=list2;
            result = list1;
        }
        else{
            l1=list2;
            l2=list1;
            result=list2;
        }

        temp = l1;
        l1 = l1->next;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<=l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }

        while(l1!=NULL){
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }

        while(l2!=NULL){
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }

        return result;
         
    }
};
