class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0); // Initialize the result array with zeros.

        for (int i = 0; i < n; i++) {
            if (k > 0) {
                int sum = 0;
                for (int j = 1; j <= k; j++) { // Sum the next `k` elements.
                    sum += code[(i + j) % n];
                }
                result[i] = sum;
            } 
            else if (k < 0) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) { // Sum the previous `k` elements.
                    sum += code[(i - j + n) % n];
                }
                result[i] = sum;
            } 
            else {
                result[i] = 0; // If `k == 0`, all elements are zero.
            }
        }

        return result;
    }
};
