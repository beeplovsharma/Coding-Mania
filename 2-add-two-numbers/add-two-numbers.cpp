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
        ListNode *dummy = new ListNode(-1);
        int sum = 0,carry=0,rem=0;
        ListNode *temp = dummy;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL) sum = l2->val + carry;
            else if(l2==NULL) sum = l1->val + carry;
            else sum = l1->val + l2->val + carry;
            carry = sum/10;
            rem = sum%10;
            ListNode *mover = new ListNode(rem);
            temp -> next = mover;
            temp = mover;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(carry){
            ListNode *mover = new ListNode(carry);
            temp ->next = mover;
            temp = mover;
        }
        return dummy->next;
    }
};