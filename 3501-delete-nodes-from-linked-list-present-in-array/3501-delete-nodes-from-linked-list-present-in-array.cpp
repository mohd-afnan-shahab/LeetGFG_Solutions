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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        while(st.find(head->val) != st.end() && head != NULL){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
        }

        ListNode* current = head;
        while(current != NULL && current->next != NULL){
            if(st.find(current->next->val) != st.end()){
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete(temp);
            }
            else {
                current = current->next;
            }
        }

        return head;
    }
};