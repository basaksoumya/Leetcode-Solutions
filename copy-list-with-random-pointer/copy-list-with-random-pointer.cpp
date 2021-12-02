/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        
        if(head == NULL)
            return head;
        
        while(curr != NULL) {
            Node* temp = new Node(curr -> val);
            temp -> next = curr -> next;
            curr -> next = temp;
            curr = curr -> next -> next;
        }
        
        curr = head;
        
        while(curr != NULL) {
            Node* randomPtr = curr -> random;
            curr = curr -> next;
            if(randomPtr == NULL) {
                curr -> random = randomPtr;
            }else {
               randomPtr = randomPtr -> next;
               curr -> random = randomPtr; 
            }
            curr = curr -> next;
        }
        
        curr = head;
        Node* prev, *dummy = head -> next;
        while(curr != NULL) {
            prev = curr -> next;
            curr -> next = prev -> next;
            if(curr -> next == NULL) {
                prev -> next = NULL;
            }else{
                prev -> next = curr -> next -> next;
            }
            curr = curr -> next;
                
        }
        
        return dummy;
    }
};