class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        // create a dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Traverse both lists while both have nodes left
        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->val < temp2->val) {
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }

        // Attach remaining nodes if one of the lists still has elements
        if(temp1 != nullptr) {
            temp->next = temp1;
        } else {
            temp->next = temp2;
        }

        return dummy->next;  // Skip the dummy node
    }
};
