#include<bits/stdc++.h>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        while(fast!=NULL){
            fast = fast->next;
            n--;
            if(n==0) break;
        }

        if(fast==NULL){
            return head->next;
        }

        ListNode *slow = head;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *nodeToBeDeleted = slow->next;
        slow -> next = nodeToBeDeleted->next;
        delete(nodeToBeDeleted);
        return head;
    }
};