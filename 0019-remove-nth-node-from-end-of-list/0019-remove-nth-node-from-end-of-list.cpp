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
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp -> next;
            size++;
        }
        if(size == 1 & n == 1)
            return NULL;
        int count = size - n;
        temp = head;
        if(count == 0)
            head = head -> next;
        else{
        while(count != 1){
            temp = temp -> next;
            count--;
}       
        ListNode* fut = temp -> next;
        temp -> next = temp -> next -> next;
        delete fut;
        }
        return head;

    }
    
};