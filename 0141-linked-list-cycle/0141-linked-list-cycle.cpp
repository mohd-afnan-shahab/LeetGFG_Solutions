/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// using the TORTOISE AND HARE APPROACH (slow and fast pointer)

class Solution {
public:
    bool hasCycle(ListNode *head) {     

        // taking slow and fast pointer
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer != nullptr && fastPointer -> next != nullptr){

            slowPointer = slowPointer -> next;            // move slow by 1
            fastPointer = fastPointer -> next -> next;    // move fast by 2

            // at any point ( slow == fast ), there is a loop
            if(slowPointer == fastPointer){
                return true;
            }
        }

        return false;
    }
};