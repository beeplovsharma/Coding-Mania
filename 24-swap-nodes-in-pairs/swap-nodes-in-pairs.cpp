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
    ListNode* fun(ListNode* head){
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;

        ListNode* temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head->next = fun(head->next);
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        return fun(head);
    }
};