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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode *curr = headA;
        
        while(curr != NULL) {
            n1++;
            curr = curr -> next;
        }
        
        curr = headB;
        
        while(curr != NULL) {
            n2++;
            curr = curr -> next;
        }
        ListNode *temp = headB;
        curr = headA;
        if(n1 > n2) {
            int k = n1 - n2;
            
            while(k--) {
                curr = curr -> next;
            }   
        }else {
            int k = n2 - n1;
            while(k--) {
                temp = temp -> next;
            }
        }
        
        while(curr != NULL && temp != NULL) {
            if(curr == temp)
                return curr;
            curr = curr -> next;
            temp = temp -> next;
        }
            
        return NULL;
    }
};