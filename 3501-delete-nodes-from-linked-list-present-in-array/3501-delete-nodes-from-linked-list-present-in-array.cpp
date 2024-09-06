class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (head == NULL || nums.empty()) return head; // If list is empty or nums is empty

        unordered_set<int> st(nums.begin(), nums.end());

        // Remove matching nodes from the beginning of the list
        while (head != NULL && st.find(head->val) != st.end()) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // Now process the rest of the list
        ListNode* current = head;
        while (current != NULL && current->next != NULL) {
            if (st.find(current->next->val) != st.end()) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
