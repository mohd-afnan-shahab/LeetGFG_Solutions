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
    
    // TC = O(N) and SC = O(N)
    
    ListNode* reverseList(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // insert temp into stack
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;        // reset temp to head
        while(temp != NULL){
            temp->val = st.top();
            st.pop();

            temp = temp->next;
        }

        return head;
    }
};