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
    ListNode* getMid(ListNode *head) {
        ListNode *fast = head, *slow = head;
        
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    
    ListNode* getReverse(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* curr = head, *prev = NULL,*next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
            return;
        ListNode* mid = getMid(head);
        
        ListNode* secondHalf = mid -> next;
        mid -> next =  NULL;
        ListNode *revHalf = getReverse(secondHalf);
        
        while(head != NULL && revHalf != NULL) {
            ListNode* temp = head -> next; 
            head -> next = revHalf;
            revHalf = revHalf -> next;
            head -> next -> next = temp;
            head = temp;
            
        }
    }
};