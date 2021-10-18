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
    
    ListNode* merge(ListNode *head1,ListNode *head2) {
        if(!head1)
            return head2;
        if(!head2)
            return head1;
        
        ListNode *ans = NULL;
        
        if(head1 -> val <= head2 -> val) {
            ans = head1;
            ans -> next = merge(head1 -> next, head2);
        }
        else{
            ans = head2;
            ans -> next = merge(head1,head2 -> next);
        }
        return ans;
    }
    
    
    void findMiddle(ListNode *head,ListNode **first,ListNode **second) {
        ListNode *fastPtr = head,*slowPtr = head;
        
        while(!fastPtr && !fastPtr) {
            fastPtr = fastPtr -> next -> next;
            slowPtr = slowPtr -> next;
        }
        
        *first = head;
        *second = slowPtr -> next;
        slowPtr -> next = NULL;
    }
    
    void mergeSort(ListNode **head) {
        ListNode *temp = *head;
        ListNode *first, *second;
        
        if(!temp || !temp -> next)
             return;
        findMiddle(temp,&first,&second);
        mergeSort(&first);
        mergeSort(&second);
        *head = merge(first,second);
    }
    
    
    ListNode* sortList(ListNode* head) {
        mergeSort(&head);
        return head;
    }
};