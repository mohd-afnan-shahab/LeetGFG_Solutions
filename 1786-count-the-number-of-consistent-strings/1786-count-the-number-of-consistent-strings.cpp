class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int mask = 0;       

        for (auto &ch : allowed) {
            mask = mask | (1 << (ch - 'a'));  // Create a bitmask for the allowed characters
        }

        int count = 0;

        for (auto &word : words) {
            bool isConsistent = true;

            for (auto &ch : word) {
                if (((mask >> (ch - 'a')) & 1) == 0) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent) count++;
        }

        return count;
    }
};
