class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Create temp array to store first m elements of nums1
        vector<int> temp;
        for(int i = 0; i < m; i++) {
            temp.push_back(nums1[i]);
        }
        
        int i = 0;  // for temp array
        int j = 0;  // for nums2
        int index = 0;  // for nums1
        
        // Merge while elements exist in both arrays
        while(i < m && j < n){
            if(temp[i] <= nums2[j]){
                nums1[index] = temp[i];
                i++;
            }
            else {
                nums1[index] = nums2[j];
                j++;
            }
            index++;
        }
        
        // Copy remaining elements from temp
        while(i < m){
            nums1[index] = temp[i];
            i++;
            index++;
        }
        
        // Copy remaining elements from nums2
        while(j < n){
            nums1[index] = nums2[j];
            j++;
            index++;
        }
    }
};