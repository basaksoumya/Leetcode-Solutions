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
    ListNode* removeElements(ListNode* head, int val) {
        
        // if(head == NULL || (head -> next == NULL && head -> val == val))
        //     return NULL;
        // if(head == NULL || (head -> next == NULL && head -> val != val))
        //     return head;
        ListNode *curr = head;
        
        while(curr != NULL && curr -> val == val) {
            ListNode *temp = curr;
            curr = curr -> next;
            head = curr;
            delete temp;
        }
        
        ListNode *prev = NULL;
        curr = head;
        
        while(curr != NULL) {
            if(curr != NULL && curr -> val == val) {
                ListNode *temp = curr;
                curr = curr -> next;
                prev -> next = curr;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};