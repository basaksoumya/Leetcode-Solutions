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
        
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *curr = head, *next = NULL, *prev = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *head = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = head;
        int carry = 0;
        
        while(p != NULL || q != NULL) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + carry;
            
            
            carry = sum / 10;
            curr -> next = new ListNode(sum % 10);
            curr = curr -> next;
            if(p)
                p = p -> next;
            if(q)
                q = q -> next; 
        }
        
        if(carry > 0) {
            curr -> next = new ListNode(carry);
        }
        head = reverseList(head -> next);
        return head;  
    }
};