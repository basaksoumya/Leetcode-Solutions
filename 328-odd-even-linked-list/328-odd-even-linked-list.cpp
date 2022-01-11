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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* root = head -> next,*curr = head,*temp = root,*prev;
        
        while(temp != NULL && temp -> next != NULL) {
            prev = curr -> next;
            curr -> next = prev -> next;
            prev = curr;
            curr = curr -> next;
            if(temp -> next) {
                temp -> next = curr -> next;
                temp = temp -> next;
            }
             
        }
        
        curr -> next = root;
        return head;
    }
};