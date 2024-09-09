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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        int topBoundary = 0, leftBoundary = 0;
        int bottomBoundary = m - 1, rightBoundary = n - 1;
        vector<vector<int>> matrix(m, vector<int>(n, -1)); // Initialize matrix with -1

        while (topBoundary <= bottomBoundary && leftBoundary <= rightBoundary) {
            
            // Fill the top row
            for (int i = leftBoundary; head != nullptr && i <= rightBoundary; i++) {
                matrix[topBoundary][i] = head->val;
                head = head->next;
            }
            topBoundary++; // Move the top boundary down

            // Fill the right column
            for (int i = topBoundary; head != nullptr && i <= bottomBoundary; i++) {
                matrix[i][rightBoundary] = head->val;
                head = head->next;
            }
            rightBoundary--; // Move the right boundary left

            // Fill the bottom row
            for (int i = rightBoundary; head != nullptr && i >= leftBoundary; i--) {
                matrix[bottomBoundary][i] = head->val;
                head = head->next;
            }
            bottomBoundary--; // Move the bottom boundary up

            // Fill the left column
            for (int i = bottomBoundary; i >= topBoundary && head != nullptr; i--) {
                matrix[i][leftBoundary] = head->val;
                head = head->next;
            }
            leftBoundary++; // Move the left boundary right

        }

        return matrix;
    }
};
