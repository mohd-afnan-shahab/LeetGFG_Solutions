class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(const auto& num : nums){
            string str = to_string(num);    // convert int to string
            int length = str.length();      // length of the string

            if(length % 2 == 0){
                count++;
            }
        }
        return count;
    }
};