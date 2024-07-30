class Solution {
public:

    bool binarySearch(vector<int>& nums, int target){
        int n = nums.size();

        int low = 0;
        int high = n-1;
        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else 
                high = mid - 1;
        }

        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        unordered_set<int> st;

        for(auto &num:nums2){
            if(binarySearch(nums1, num)){
                st.insert(num);
            }
        }
        vector<int> result(st.begin(), st.end());
        return result;
    }
};