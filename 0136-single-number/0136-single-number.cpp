class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;

        // Count the occurrences of each number
        for(auto num:nums){
            mpp[num]++;
        }

        for(auto it : mpp){
            if(it.second == 1){
                return it.first;
            }
        }

        return -1;
    }
};