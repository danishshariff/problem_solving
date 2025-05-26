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
    ListNode* oddEvenList(ListNode* head) {

        // for value based
        // if (!head) return nullptr;

        // ListNode* oddHead = new ListNode(-1);   // dummy node for odd values
        // ListNode* evenHead = new ListNode(-1);  // dummy node for even values
        // ListNode* odd = oddHead;
        // ListNode* even = evenHead;
        // ListNode* temp = head;

        // while (temp != nullptr) {
        //     if (temp->val % 2 == 1) {
        //         odd->next = temp;
        //         odd = odd->next;
        //     } else {
        //         even->next = temp;
        //         even = even->next;
        //     }
        //     temp = temp->next;
        // }

        // // Important: terminate the even list to avoid cycles
        // even->next = nullptr;

        // // Connect odd list to even list
        // odd->next = evenHead->next;

        // return oddHead->next;

        //index based

        if (!head) return nullptr;

        ListNode* oddHead = new ListNode(-1);   // dummy for odd-indexed nodes
        ListNode* evenHead = new ListNode(-1);  // dummy for even-indexed nodes
        ListNode* odd = oddHead;
        ListNode* even = evenHead;

        ListNode* temp = head;
        int index = 1; // start from position 1

        while (temp != nullptr) {
            if (index % 2 == 1) {
                odd->next = temp;
                odd = odd->next;
            } else {
                even->next = temp;
                even = even->next;
            }
            temp = temp->next;
            index++;
        }

        // End the even list properly to avoid cycles
        even->next = nullptr;

        // Link odd list to even list
        odd->next = evenHead->next;

        return oddHead->next;
    }
};

  