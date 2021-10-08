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
    ListNode* middleNode(ListNode* head) {
        ListNode *slowPtr = head, *fastPtr = head;
        
        while(fastPtr != NULL && fastPtr -> next != NULL) {
            fastPtr = fastPtr -> next -> next;
            slowPtr = slowPtr -> next;
        }
        
        return slowPtr;
    }
};