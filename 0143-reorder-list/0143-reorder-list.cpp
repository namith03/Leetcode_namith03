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
    void reorderList(ListNode* head) {
        
        stack<int> st;
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp -> next;
            size++;
        }
        int mid = size/2;
        ListNode* temp1 = head;
        while(mid != 0){
            temp1 = temp1 -> next;
            mid--;
}       
        if( size % 2 != 0)
            temp1 = temp1 -> next;
        while(temp1 != NULL){
            st.push(temp1 -> val);
            temp1 = temp1 -> next;
}
        ListNode* temp2 = head;
        while(!st.empty()){
            ListNode *fut = temp2 -> next;
            ListNode *dummy = new ListNode();
            dummy -> val = st.top();
            temp2 -> next = dummy;
            dummy -> next = fut;
            temp2 = temp2 -> next -> next;
            if(size % 2 == 0 && st.size() == 1)
                dummy -> next = NULL;
            st.pop();
    }
        temp2 -> next = NULL;
    }
};