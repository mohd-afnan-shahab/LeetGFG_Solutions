class Solution {
public:

    int maxNodeAdjSum(vector<int>& arr) {
        int n = arr.size();

        int prev = arr[0];
        int prev2 = 0;

        for(int i = 1; i < n; i++){

            int pick = arr[i];

            if(i > 1) pick += prev2;

            int notPick = 0 + prev;

            int currI = max(pick, notPick);

            prev2 = prev;
            prev = currI;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        
        vector<int> temp1, temp2;

        int n = nums.size();

        // array has only 1 element
        if(n == 1) return nums[0];

        for(int i = 0; i < n; i++){

            // exclude first ele from array
            if(i != 0){
                temp1.push_back(nums[i]);
            }

            if(i != n-1){
                temp2.push_back(nums[i]);
            }
        }

        int maxAnswer = max(maxNodeAdjSum(temp1), maxNodeAdjSum(temp2));
        
        return maxAnswer;
    }
};