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
         if (head == NULL) {
        return NULL;
    }

    //brute
        // ListNode* temp=head;
        // int cnt=0;
        // while(temp!=nullptr){
        //     cnt++;
        //     temp=temp->next;
        // }

        // int res=(cnt-n);
        // temp=head;
        // if (res == 0) {
        //     ListNode* newHead = head->next;
        //     delete head;
        //     return newHead;
        // }

        // while(temp!=nullptr){
        //     res=res-1;
        //     if(res==0){
        //         break;
        //     }
        //     temp=temp->next;

        // }
        // ListNode* dltnode=temp->next;
        // temp->next=temp->next->next;
        // delete(dltnode);
        // return head;

        //optimal

        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            return head->next;
        }
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
         ListNode* dltnode=slow->next;
        slow->next=slow->next->next;
        delete(dltnode);
        return head;
    }
};