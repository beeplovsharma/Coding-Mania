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
        ListNode *t1=list1,*t2=list2;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while(t1!=NULL && t2!=NULL){
            if(t1!=NULL && t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else if(t2!=NULL && t1->val >= t2->val){
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        while(t1!=NULL){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        while(t2!=NULL){
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
        return dummy->next;
    }
};