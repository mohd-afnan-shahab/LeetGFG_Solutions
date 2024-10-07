class Solution {
public:
    // TIME COMPLEXITY - O(N^2) ans SPACE COMPLEXITY - O(1)
    int minLength(string s) {
        size_t pos;

        while( (pos = s.find("AB")) != string :: npos || (pos = s.find("CD")) != string :: npos){
            s.erase(pos, 2);
        }

        return s.length();
    }
};