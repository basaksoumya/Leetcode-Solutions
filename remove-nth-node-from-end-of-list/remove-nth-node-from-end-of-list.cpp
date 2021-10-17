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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr = head, *followPtr = head, *prev = head;
        
        if(n == 1 && head -> next == NULL)
            return NULL;
        
        while(n--) {
            ptr = ptr -> next;
        }
        
        if(ptr == NULL) {
            ListNode *temp = head;
            head = temp -> next;
            delete temp;
            return head;
        }
        
        while(ptr != NULL) {
            ptr = ptr -> next;
            prev = followPtr;
            followPtr = followPtr -> next;
        }
        ListNode *temp = prev -> next;
        prev -> next = temp -> next;
        delete temp;
        
        return head;
    }
};