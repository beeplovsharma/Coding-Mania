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
    ListNode* fun(ListNode* head, int val){
        if(head==NULL) return head;
        
        head->next = fun(head->next,val);

        if(head->val==val){
            return head->next;
        }

        return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
        return fun(head,val);
    }
};