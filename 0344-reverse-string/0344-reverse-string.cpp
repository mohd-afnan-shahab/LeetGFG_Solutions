class Solution {
public:
    // void reverseString(vector<char>& s) {
    //     int n = s.size();
    //     int l = 0;
    //     int r = n - 1;

    //     while(l <= r){
    //         swap(s[l], s[r]);
    //         l++;
    //         r--;
    //     }
        
    // }


    // solved using stackk

    void reverseString(vector<char>& s){
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            st.push(s[i]);
        }

        int i = 0;
        while(!st.empty()){
            s[i] = st.top();
            i++;
            st.pop();
        }
    }
};