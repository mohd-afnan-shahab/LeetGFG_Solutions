class Solution {
public:
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