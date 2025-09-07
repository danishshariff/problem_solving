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
    // Helper: reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find middle using slow & fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHead = reverse(slow->next);
        slow->next = NULL; // split the list

        // Step 3: Merge two halves
        ListNode* firstHead = head;
        while (secondHead) {
            ListNode* temp1 = firstHead->next;
            ListNode* temp2 = secondHead->next;

            firstHead->next = secondHead;
            secondHead->next = temp1;

            firstHead = temp1;
            secondHead = temp2;
        }
    }
};
