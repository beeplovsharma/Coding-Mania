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
    ListNode* tleft;
    int size;
    void fun(ListNode* tright, int floor){
        if(tright==NULL) return;

        fun(tright->next,floor+1);

        if(floor>=size/2){
            int temp = tright->val;
            tright->val = tleft->val;
            tleft->val = temp;

            tleft=tleft->next;
        }
    }

    int getSize(ListNode* head){
        ListNode* temp=head;
        int size = 0;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        return size;
    }
    ListNode* reverseList(ListNode* head) {
        size = getSize(head);
        tleft=head;
        fun(head,0);
        return head;
    }
};