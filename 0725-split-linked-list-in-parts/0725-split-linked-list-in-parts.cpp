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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // count the length of LL
        int L = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            L++;
            temp = temp -> next;
        }

        vector<ListNode*> result(k, nullptr);

        int NodesInEach = L / k;
        int remainingNodes = L % k;

        ListNode* current = head;
        ListNode* prev = nullptr;

        // Iterate over result vector
        for(int i = 0; i < k; i++){

            result[i] = current;

            for(int j = 1; j <= NodesInEach + (remainingNodes > 0 ? 1 : 0); j++){

                prev = current;
                current = current -> next;

            }

            if(prev != nullptr){
                prev -> next = nullptr;
            }
           
            remainingNodes--;
        }

        return result;
    }
};