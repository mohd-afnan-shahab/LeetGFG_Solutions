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

// TORTOISE AND HARE APPROACH (slow and fast pointer)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Edge case: if the list is empty
        if (head == nullptr) {
            return nullptr;
        }

        // Initialize slowPointer and fastPointer to the head
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        // Move slowPointer by 1 and fastPointer by 2
        // Loop will stop when fastPointer reaches the end of the list
        while (fastPointer != nullptr && fastPointer->next != nullptr) {
            slowPointer = slowPointer->next;            // slow moves by 1
            fastPointer = fastPointer->next->next;      // fast moves by 2
        }

        // slowPointer will now be pointing to the middle node
        return slowPointer;
    }
};
