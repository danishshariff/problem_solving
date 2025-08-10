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
    int pairSum(ListNode* head) {
     ListNode* temp=head;
     int sum=0;
     int count=0;
     vector<int> arr;
     while(temp!=nullptr){
        arr.push_back(temp->val);
        temp=temp->next;
     }


     int n=arr.size();
        for(int i=0;i<n;i++){
            sum=max(sum,arr[i]+arr[n-1-i]);
        }
        return sum;
    }
};