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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }

        // Step 1: Find the length of the linked list
        ListNode* temp = head;
        int n = 1;  // List has at least one node
        while (temp->next != NULL) {
            n++;
            temp = temp->next;
        }

        // Step 2: Adjust k to be within the bounds of the list
        k = k % n;
        if (k == 0) return head;  // No rotation needed if k is a multiple of n

        // Step 3: Traverse the list to find the (n-k)-th node
        temp->next = head;  // Make the list circular
        ListNode* new_tail = head;
        for (int i = 1; i < n - k; i++) {
            new_tail = new_tail->next;
        }

        // Step 4: Set the new head and break the circular link
        ListNode* new_head = new_tail->next;
        new_tail->next = NULL;

        return new_head;
    }
};