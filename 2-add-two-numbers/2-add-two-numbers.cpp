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
        
        int carry = 0;
        int sum = 0;
        ListNode* temp = new ListNode();
        ListNode* output = temp;
        ListNode* prev = temp;
        // O(N)
        while(l1 || l2){
            sum = 0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            
            temp->val = sum;
            temp->next = new ListNode(0);
            prev = temp;
            temp = temp->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry) temp->val = 1;
        else prev->next = NULL;
        
        
        return output;
    }
};