/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *curr = node;
        ListNode *front = node->next;
        while(front->next!=NULL){
            curr->val = front->val;
            curr = front;
            front = front->next;
        }
        curr->val = front->val;
        delete front;
        curr->next = NULL;
    }
};