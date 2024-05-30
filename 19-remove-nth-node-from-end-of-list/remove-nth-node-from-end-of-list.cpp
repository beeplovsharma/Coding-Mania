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
    int countLL(ListNode *head){
        ListNode *temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = countLL(head);
        int req = len-n;
        if(n==len){
            ListNode *newHead = head;
            newHead = newHead -> next;
            delete(head);
            return newHead;
        }
        ListNode * temp = head;
        while(temp!=NULL){
            req--;
            if(req == 0) break;
            temp = temp->next;
        }

        ListNode *front = temp->next;
        temp -> next = front->next;
        front->next = NULL;
        delete(front);
        return head;
    }
};