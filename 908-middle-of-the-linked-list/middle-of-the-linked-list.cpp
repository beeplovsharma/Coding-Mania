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
    int countLL(ListNode *head){
        ListNode *temp = head;
        int cnt = 0;
        while(temp!=NULL){
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int n = countLL(head);
        int mid = n/2;
        ListNode *temp = head;
        for(int i=0;i<mid;i++){
            temp = temp->next;
        }
        return temp;
    }
};