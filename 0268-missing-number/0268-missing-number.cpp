class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // int expected_sum = (n * (n + 1))/2;     // Sum of numbers from 0 to n

        // int actual_sum = 0;
        // for(auto num:nums){
        //     actual_sum += num;
        // }
        // return (expected_sum - actual_sum);


        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        // iterating through the array and numbers from 0 to n..
        for(int i = 0; i < n; i++){
            xor1 = xor1 ^ i;
            xor2 = xor2 ^ nums[i];
        }

        // include the last number n in xor1 calc
        xor1 = xor1 ^ n;

        return xor1 ^ xor2;
    }
};