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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == nullptr || head -> next == nullptr) return nullptr;

        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        fastPointer = head -> next -> next;      // skip 1 step of slow

        while(fastPointer != nullptr && fastPointer -> next != nullptr){

            slowPointer = slowPointer -> next;
            fastPointer = fastPointer -> next -> next;
            
        }

        ListNode* midNode = slowPointer -> next;
        slowPointer -> next = slowPointer -> next -> next;
        delete(midNode);

        return head;
    }
};