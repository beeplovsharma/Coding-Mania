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
    // ListNode *reverse(ListNode* head){
    //     ListNode * back = NULL;
    //     ListNode * curr = head;
    //     while(curr!=NULL){
    //         ListNode * front = curr->next;
    //         curr -> next = back;
    //         back = curr;
    //         curr = front;
    //     }
    //     return back;
    // }
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        int ans = 0;
        while(temp!=NULL){
            ans *= 2;
            ans += (temp->val);
            temp = temp->next;
        }
        return ans;
    }
};