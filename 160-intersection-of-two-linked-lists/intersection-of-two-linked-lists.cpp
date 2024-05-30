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
    int countLL(ListNode *head){
        ListNode *temp;
        int cnt =0;
        while(temp!=NULL){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        while(t1!=t2){
            if(t1) t1 = t1 -> next;
            else t1 = headA;

            if(t2) t2 = t2 -> next;
            else t2 = headB;
        }
        if(t1==t2) return t1;
        return NULL;
    }
};