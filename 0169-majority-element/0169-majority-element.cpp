class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element;
        int count = 0;

        for(auto num : nums){
            if(count == 0){
                count = 1;
                element = num;
            }
            else if(element == num){
                count++;
            }
            else
                count--;
        }

        // second pass to confirm the element
        count = 0;
        for(auto num : nums){
            if(element == num){
                count++;
            }
        }

        if(count > (n / 2)) return  element;
        return -1;
    }
};