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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(curr != NULL) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *curr = head;
        int len = 0;
        while(curr != NULL) {
            len++;
            curr = curr -> next;
        }
        ListNode* fastPtr = head,*slowPtr = head,*prev = head;
        while(fastPtr != NULL && fastPtr -> next != NULL) {
            fastPtr = fastPtr -> next -> next;
            prev = slowPtr;
            slowPtr = slowPtr -> next;
        }
        if(len % 2 == 1) {
            prev = slowPtr;
            slowPtr = slowPtr -> next;
        }
        prev -> next = reverseList(slowPtr);
        slowPtr = prev->next;
        ListNode* temp = head;
        
        // while(temp != NULL) {
        //     cout  << "Data = " << temp -> val << endl;
        //     temp = temp -> next;
        // }
        
        
        //if(temp -> val == slowPtr -> val) return false;
        while(slowPtr != NULL) {
            if(temp -> val != slowPtr -> val)
                return false;
            
            slowPtr = slowPtr -> next;
            temp = temp -> next;
            
        }
        prev = temp;
        temp = temp -> next;
        prev = reverseList(temp);
        return true;
    }
};