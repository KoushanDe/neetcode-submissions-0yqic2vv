/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> adrs;

        Node* curr = head;

        while(curr!=NULL){
            Node* newNode = new Node(curr->val);
            adrs[curr] = newNode;
            curr = curr->next;
        }

        curr = head;

        while(curr!=NULL){
            if(curr->next==NULL){
                adrs[curr]->next = NULL;
            }
            if(curr->random==NULL){
                adrs[curr]->random = NULL;
            }
            adrs[curr]->next = adrs[curr->next];
            adrs[curr]->random = adrs[curr->random];
            curr = curr->next;
        }

        return adrs[head];
    }
};
