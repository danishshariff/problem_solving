/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Assume the node to be deleted is not the tail.
        if(node == nullptr || node->next == nullptr) {
            return; // Shouldn't happen based on the problem description.
        }
        
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        
        // Store a reference to the next node
        ListNode* temp = node->next;
        
        // Bypass the next node
        node->next = node->next->next;
        
        // Free the bypassed node (optional, not always required in LeetCode problems)
        delete temp;
    }
};
