class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL)
            return NULL;
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* head, *list ,*list1 = l1 , *list2 = l2;
        
        if(list1->val >= list2->val) {
            head = list2;
            list2 = list2 -> next;
        }else{
            head = list1;
            list1 = list1 -> next;
        }
        
        list = head;
        
        while(list1 != NULL && list2 != NULL) {
            
            if(list1 -> val >= list2 -> val){
                list ->next = list2;
                list2 = list2 -> next;
            }
            else{
                list -> next = list1;
                list1 = list1 -> next;
            }
            
            list = list -> next;
        }
        
        while(list1 != NULL) {
            list->next = list1;
            list = list -> next;
            list1 = list1 -> next;
        }
        
        while(list2 != NULL) {
            list ->next = list2;
            list = list -> next;
            list2 = list2 -> next;
        }
        
        return head;
    }
};