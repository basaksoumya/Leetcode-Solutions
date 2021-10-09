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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode *curr = head;
        
        while(curr != NULL) {
            ListNode *prev = curr;
            curr = curr ->next;
            while(curr != NULL && prev -> val == curr -> val) {
                ListNode *temp = curr;
                curr = curr -> next;
                prev -> next = curr;
                delete temp;
            }
        }
        return head;
    }
};