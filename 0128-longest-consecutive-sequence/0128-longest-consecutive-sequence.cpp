class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        int longest = 1;
         
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        for(auto& it : st){

            int x = it;

            // x-1 not present in st.
            if(st.find(x - 1) == st.end()){
                int count = 1;

                while(st.find(x + 1) != st.end()){
                    x = x + 1;
                    count++;
                }

                longest = max(longest, count);
            }
        }


        return longest;
    }
};