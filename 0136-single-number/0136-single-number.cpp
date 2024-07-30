class Solution {
public:

    // // time and space complexity is O(n) and O(n)
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int, int> mpp;

    //     // Count the occurrences of each number
    //     for(auto num:nums){
    //         mpp[num]++;
    //     }

    //     for(auto it : mpp){
    //         if(it.second == 1){
    //             return it.first;
    //         }
    //     }

    //     return -1;
    // }

    


    // time and space complexity is O(n) and O(1)
    int singleNumber(vector<int>& nums){
        int result = 0;
        for(auto num : nums){
            result = result ^ num;
        }
        
        return result;
    }
};