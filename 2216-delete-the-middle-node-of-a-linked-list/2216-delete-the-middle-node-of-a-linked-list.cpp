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
        // Traverse LL to calc length 
        ListNode* temp = head;
        int length = 0;

        while(temp != nullptr){
            length++;
            temp = temp -> next;
        }

        // calc mid positon 
        int middle = length / 2;       
        temp = head;

        while(temp != nullptr){
            middle--;

            if(middle == 0){
                ListNode* midNode = temp -> next;
                temp -> next = temp -> next -> next;
                delete(midNode);
            }

            temp = temp -> next;
        }
        return head;

    }
};