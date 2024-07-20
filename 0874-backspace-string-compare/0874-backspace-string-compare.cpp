class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st;
        stack<int> stt;

        for(int i = 0; i < s.size(); i++){

            if(s[i] != '#'){
                st.push(s[i]);
            }
            else {
                if(!st.empty()) st.pop();
            }
        }

        for(int i = 0; i < t.size(); i++){

            if(t[i] != '#'){
                stt.push(t[i]);
            }
            else {
                if(!stt.empty()) stt.pop();
            }

        } 

        // Compare both stacks  
        return st == stt; 
    }   
};  