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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head -> next == NULL) 
            return head;
        int len = 1 ,size = 0;
        ListNode *curr = head, *prev = head,*follow = head;
        while(curr != NULL) {
            size++;
            curr = curr -> next;
        }
        
        if(k == 0 || k%size == 0)
            return head;
        curr = head;
        k = k%size;
        while(len < k) {
            len++;
            curr = curr -> next;
        }
        while(curr -> next != NULL) {
            curr = curr -> next;
            prev = follow;
            follow = follow -> next;
        }
        prev -> next = NULL;
        prev = NULL;
        curr -> next = head;
        head = follow;
        return head;
    }
};