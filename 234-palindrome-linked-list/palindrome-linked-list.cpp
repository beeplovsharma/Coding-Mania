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
    bool fun(ListNode* tright){
        if(tright==NULL) return true;

        bool faith = fun(tright->next);

        if(faith==false) return false;
        else if(tright->val != tleft->val) return false;
        else{
            tleft = tleft->next;
            return true;
        }

    }
    bool isPalindrome(ListNode* head) {
        tleft=head;
        return fun(head);
    }
};