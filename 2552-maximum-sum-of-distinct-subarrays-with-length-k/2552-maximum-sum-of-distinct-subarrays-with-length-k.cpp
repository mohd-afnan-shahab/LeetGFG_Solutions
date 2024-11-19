class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long currWindowSum = 0;

        unordered_set<int> st;

        int i = 0, j = 0;

        while(j < n){

            while(st.find(nums[j]) != st.end()){

                // if duplicates found
                currWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            st.insert(nums[j]);
            currWindowSum += nums[j];

            // check if the curr window size is equal to k
            if(j - i + 1 == k){
                ans = max(ans, currWindowSum);

                // shrink the window from left
                currWindowSum -= nums[i];

                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return ans;
    }
};