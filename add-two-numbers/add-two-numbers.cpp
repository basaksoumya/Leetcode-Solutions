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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *num1 = l1, *num2 = l2,*prev;
        int carry = 0,len1 = 0,len2 = 0;
        while(num1 != NULL) {
            num1 = num1 -> next;
            len1++;
        }
         while(num2 != NULL) {
            num2 = num2 -> next;
            len2++;
        }
        num1 = l1,num2 = l2;
        ListNode *ans;
        
        if(len1 >= len2)
            ans = num1;
        else
            ans = num2;
        
        while(num1 != NULL && num2 != NULL) {
            
            ans -> val = num1 -> val + num2 -> val + carry;
            if(ans -> val >= 10) {
                ans -> val = ans -> val - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            prev = ans;
            ans = ans -> next;
            num1 = num1 -> next;
            num2 = num2 -> next;
        }
        
        while(num1 != NULL) {
            ans -> val = carry + num1 -> val;
            if(ans -> val >= 10) {
                ans -> val = ans -> val - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            prev = ans;
            ans = ans -> next;
            num1 = num1 -> next;
        }
        
        while(num2 != NULL) {
            ans -> val = carry + num2 -> val;
            if(ans -> val >= 10) {
                ans -> val = ans -> val - 10;
                carry = 1;
            }else{
                carry = 0;
            }
            prev = ans;
            ans = ans -> next;
            num2 = num2 -> next;
        }
        
        if(carry) {
            prev -> next = new ListNode(carry);
        }
        
        return (len1 >= len2) ? l1 : l2;
    }
};