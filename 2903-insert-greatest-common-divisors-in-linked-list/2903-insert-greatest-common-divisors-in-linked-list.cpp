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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        // if list has only one or no node..
        if(head == nullptr && head -> next == nullptr) return head;

        ListNode* currNode = head;
        while(currNode && currNode -> next){

            ListNode* nextNode = currNode -> next;      // creating next node

            int gcd = __gcd(currNode -> val, nextNode -> val);     // calc gcd

            ListNode* gcdNode = new ListNode(gcd);      // creating gcd Node

            currNode -> next = gcdNode;
            gcdNode -> next = nextNode;

            currNode = nextNode;
       }

       return head;
    }
};