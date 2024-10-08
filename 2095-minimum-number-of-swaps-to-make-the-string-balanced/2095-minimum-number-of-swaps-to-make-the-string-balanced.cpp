class Solution {
public:
    // TIME COMPLEXITY - O(N) ans SPACE COMPLEXITY - O(N)
    int minSwaps(string s) {
        stack<char> st;

        for(auto& ch : s){
            if(ch == '[') st.push(ch);
            else if(!st.empty() && ch == ']'){
                st.pop();   // A balanced pair of brackets
            } 
        } 

        int unbalancedCount = st.size();
        return (unbalancedCount + 1) / 2;
    }
};