class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int evenDigitCount = 0;

        for(const auto& num : nums){
            int digitCount = 0;
            int temp = num;
            while(temp > 0){
                temp = temp / 10;
                digitCount++;
            }

            if(digitCount % 2 == 0){
                evenDigitCount++;
            }
        }
        return evenDigitCount;
    }
};