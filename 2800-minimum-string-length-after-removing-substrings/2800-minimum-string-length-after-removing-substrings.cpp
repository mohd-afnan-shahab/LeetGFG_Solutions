class Solution {
public:
    int minLength(string s) {
        size_t pos;

        while( (pos = s.find("AB")) != string :: npos || (pos = s.find("CD")) != string :: npos){
            s.erase(pos, 2);
        }

        return s.length();
    }
};