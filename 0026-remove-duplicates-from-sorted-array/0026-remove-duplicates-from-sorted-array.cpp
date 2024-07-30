class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //set contains unique elements and it taked in ascending order

        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);             // o(NlogN)
        }

        //iterate in set
        int ind = 0;
        for(auto it:st){
            nums[ind] = it;
            ind++;
        }
        
        return ind; //count them
    }
};