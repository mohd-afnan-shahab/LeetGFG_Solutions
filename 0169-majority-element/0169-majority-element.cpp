class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();

    //     map<int, int> mpp;

    //     for(int i = 0; i < n; i++){
    //         mpp[nums[i]]++;
    //     }

    //     // iterate in map
    //     for(auto& it : mpp){
    //         if(it.second > (n / 2)){
    //             return it.first;
    //         }
    //     }

    //     return -1;
    // }



    // moore's voting algo

    int majorityElement(vector<int>& nums){

        int element = 0, count = 0;

        for(int num : nums){

            if(count == 0){
                element = num;
                count = 1;
            }

            else if(num == element){
                count++;
            }

            else{
                count--;
            }
        }

        // if there exist a majority element
        return element;
    }
};