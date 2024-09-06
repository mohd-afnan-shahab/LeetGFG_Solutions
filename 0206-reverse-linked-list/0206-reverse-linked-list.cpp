class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize pointers
        ListNode* prev = nullptr;
        ListNode* current = head;

        // Traverse the list
        while (current != nullptr) {
            ListNode* front = current->next;  // Store next node

            current->next = prev;  // Reverse the current node's pointer

            prev = current;  // Move prev to current
            current = front;  // Move current to next node
        }

        // prev will be the new head of the reversed list
        return prev;
    }
};
