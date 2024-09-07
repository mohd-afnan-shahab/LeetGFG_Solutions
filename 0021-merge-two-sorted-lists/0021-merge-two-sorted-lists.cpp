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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> vec;
        ListNode* temp1 = list1;
        while(temp1 != nullptr){
            vec.push_back(temp1->val);
            temp1 = temp1->next;
        }

        ListNode* temp2 = list2;
        while(temp2 != nullptr){
            vec.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(vec.begin(), vec.end());

        // lets convert vector to linked list
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        for(const auto& val : vec){
            current->next = new ListNode(val);
            current = current->next;
        }

        return dummy->next;
    }
};