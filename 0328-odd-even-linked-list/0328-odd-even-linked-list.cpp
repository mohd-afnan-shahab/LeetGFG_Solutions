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
        // edge case if list is empty
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* oddNode = head;
        ListNode* evenNode = head -> next;
        
        ListNode* evenNodeHead = head -> next;      // to attach odd to even at last

        while(evenNode != nullptr && evenNode -> next != nullptr){
            // attack oddNode to next oddNode
            oddNode -> next = evenNode -> next;
            oddNode = oddNode -> next;

            // similarly for evenNode
            evenNode -> next = oddNode -> next;
            evenNode = evenNode -> next;
        }

        // at last attach oddNode to evenNodeHead
        oddNode -> next = evenNodeHead;
        
        return head;
    }
};