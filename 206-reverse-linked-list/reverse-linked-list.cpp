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
    int getSize(ListNode* head){
        int n=0;
        ListNode *temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        return n;
    }
    ListNode* getAt(ListNode* head,int ind){
        if(head==NULL) return NULL;
        ListNode *temp=head;
        for(int i=0;i<ind;i++){
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        int n = getSize(head);
        int i=0,j=n-1;
        while(i<j){
            ListNode* di = getAt(head,i);
            ListNode* dj = getAt(head,j);

            int temp = di->val;
            di->val= dj->val;
            dj->val = temp;

            i++;
            j--;
        }
        return head;
    }
};