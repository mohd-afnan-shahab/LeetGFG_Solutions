class Solution {
public:
    // TIME COMPLEXITY - O(N) and SPACE COMPLEXITY - O(N)
    int minLength(string s) {
        stack<char> ans;

        for(auto& ch : s){
            if(!ans.empty() && ((ch == 'B' && ans.top() == 'A') || (ch == 'D' && ans.top() == 'C'))) {
                ans.pop();  
            }
            else {
                ans.push(ch);  
            }
        }

        return ans.size();
    }
};
