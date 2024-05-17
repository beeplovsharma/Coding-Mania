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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *tempH = head;

        for(int i=0;i<left-1;i++){
            tempH = tempH->next;
        }

        ListNode *tempT = tempH;
        for(int i=left;i<right;i++){
            tempT = tempT->next;
        }

        stack<int>st;
        ListNode *tH = tempH, *tT = tempT;
        while(tH != tT->next){
            st.push(tH->val);
            tH = tH->next;
        }

        tH = tempH, tT = tempT;
        while(tH!=tT->next){
            tH->val = st.top();
            st.pop();
            tH = tH->next;
        }
        return head;
    }
};