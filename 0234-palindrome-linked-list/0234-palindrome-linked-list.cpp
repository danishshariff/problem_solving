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

    ListNode* revell(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newhead=revell(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
        
    }
    bool isPalindrome(ListNode* head) {

        // brute using stack

        // stack<int> st;
        // ListNode* temp=head;
        // while(temp!=nullptr){
        //     st.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=nullptr){
        //     if(temp->val!=st.top()){
        //         return false;
        //     }
        //     st.pop();
        //     temp=temp->next;

        // }
        // return true;

        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=revell(slow->next);
        ListNode* first=head;
        ListNode* second=newhead;

        while(second!=nullptr){
            if(first->val!=second->val){
                revell(newhead);
                return false;
            }
            first=first->next;
            second=second->next;

        }
            revell(newhead);
            return true;
    }
};