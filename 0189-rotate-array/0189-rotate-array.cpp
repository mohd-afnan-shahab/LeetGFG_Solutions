class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // incase if k is greater than n

        reverse(nums, 0, n-1);  //reverse whole array
        reverse(nums, 0, k-1);  //reverse first k elements
        reverse(nums, k, n-1);  //reverse elements from k to last element
    }

    void reverse(vector<int>& nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};