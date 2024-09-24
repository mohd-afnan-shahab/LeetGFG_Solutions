class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        // insert all prefix of each element of arr1 in set
        for(auto arr : arr1){
            
            while(!st.count(arr) && arr > 0){
                st.insert(arr);

                arr = arr/10;   
            }
        }

        int maxLen = 0;
        for(auto arr : arr2){
            while(arr > 0 && !st.count(arr)){
                arr = arr / 10;
            }

            if(arr > 0){
                maxLen = max(maxLen, static_cast<int>(log10(arr) + 1));
            }
        }

        return maxLen;
    }
};