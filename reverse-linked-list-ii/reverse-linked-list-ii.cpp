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
        ListNode* curr = head , *prevHead = head, *next = NULL;
        int len = 0;
        
        if(head == NULL || head -> next == NULL)
            return head;
        if(left == right)
            return head;
        while(len+1!= left) {
            len++;
            prevHead = curr;
            curr = curr -> next;
        }
        ListNode* tail = curr, *prev = NULL;
        while(len+1 != right) {
            len++;
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        len++;
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        if(left == 1)
            head = prev;
        prevHead -> next = prev;
        tail -> next = curr;
        return head;
    }
};