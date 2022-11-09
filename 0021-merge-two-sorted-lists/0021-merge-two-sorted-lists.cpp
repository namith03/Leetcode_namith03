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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp1 = list1;
        int size1 = 0, size2 = 0;
        ListNode* temp2 = list2;
        while(temp1 != NULL){
            size1++;
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            size2++;
            temp2 = temp2 -> next;
        }
        if(size1 == 0 && size2 == 0)
            return NULL;
        if(size1 == 0)
            return list2;
        if(size2 == 0)
            return list1;
        int size = size1 + size2;
        ListNode* head = new ListNode();
        if(list1 -> val <= list2 -> val){
            head -> val = list1 -> val;
            head -> next = NULL;
            list1 = list1 -> next;
            size1--;
}
        else{
            head -> val = list2 -> val;
            head -> next = NULL;
            list2 = list2 -> next;
            size2--;
        }
        ListNode* temp = head;
        while(list1 != NULL && list2 != NULL){
            if(list1-> val <= list2 -> val){
                temp -> next = list1;
                temp = temp -> next;
                list1 = list1 -> next;
                size1--;
        }
            else if (list1 -> val > list2 -> val){   
                   temp -> next = list2;
                   temp = temp -> next;
                   list2 = list2 -> next;
                   size2--;
        }
        }
          while(size1 > 0){
                temp -> next = list1;
                temp = temp -> next;
                list1 = list1 -> next;
                size1--;
            }
            while(size2 > 0){
                temp -> next = list2;
                temp = temp -> next;
                list2 = list2 -> next;
                size2--;
            }
            temp -> next = NULL;
        return head;
    }
};