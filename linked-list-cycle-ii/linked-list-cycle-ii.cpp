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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastPtr = head, *slowPtr = head;
        
        while(fastPtr != NULL && fastPtr -> next != NULL) {
            if(fastPtr == NULL && fastPtr->next == NULL)
                return NULL;
            fastPtr = fastPtr -> next -> next;
            slowPtr = slowPtr -> next;
            
            if(fastPtr == slowPtr)
                break;
        }
        if(fastPtr == NULL || fastPtr -> next == NULL)
            return NULL;
        
        fastPtr = head;
        while(fastPtr != slowPtr) {
            fastPtr = fastPtr -> next;
            slowPtr = slowPtr -> next;
        }
        return fastPtr;
    }
};