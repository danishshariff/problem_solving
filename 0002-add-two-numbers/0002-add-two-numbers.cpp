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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//         ListNode* dummyhead= new ListNode(-1);
//         ListNode* curr=dummyhead;
//         ListNode* temp1=l1;
//         ListNode* temp2=l2;
//         int carry=0;
//         while(temp1!=NULL || temp2!=NULL){
//          int sum=carry;
//          if(temp1)sum+=temp1->val;
//          if(temp2)sum+=temp2->val;
//          ListNode* newnode= new ListNode(sum%10);
//          carry=sum/10;
//          curr->next=newnode;
//          curr=curr->next;
//          if(temp1)temp1=temp1->next;
//          if(temp2)temp2=temp2->next;


//         }
//         if(carry){
//             ListNode* newNode= new ListNode(carry);
//             curr->next=newNode;
//         }
//         return dummyhead->next;
        
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};