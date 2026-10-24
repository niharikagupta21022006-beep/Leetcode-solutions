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
        // int len = 0;
        // ListNode* temp = head;

        // while (temp != NULL) {
        //     len++;
        //     temp = temp->next;
        // }

        // int diff = len - n;
        // if (diff == 0) {
        //     ListNode* temp1 = head;
        //     head = head->next;
        //     temp1->next = NULL;
        //     delete temp1;
        // }

        // else {
        //     ListNode* curr = head;
        //     ListNode* prev = NULL;
        //     int cnt = 0;
        //     while (cnt < diff && curr != NULL) {
        //         prev = curr;
        //         curr = curr->next;
        //         cnt++;
        //     }
           
        //         prev->next = curr->next;
        //         curr->next = NULL;
        //         delete curr;
            
        // }

        

        // return head;

        
        ListNode*fast = head;
        ListNode*dummy = new ListNode(0);
        dummy->next = head;
        ListNode*slow = dummy;
        


        for(int i = 0;i<n;i++){
            fast = fast->next;
        }

       
        
        while(fast != NULL){
            
            slow = slow->next;
            fast = fast->next;
        }
        ListNode*temp = slow->next;

        slow->next = slow->next->next;
        delete temp;

        return dummy->next;
    }
};