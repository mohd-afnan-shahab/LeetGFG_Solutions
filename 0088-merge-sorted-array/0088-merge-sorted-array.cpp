class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> arr1(m);
        for(int i = 0; i < m; i++){
            arr1[i] = nums1[i];
        }

        int l = 0, r = 0;
        int idx = 0;

        while(l < m && r < n){
            if(arr1[l] < nums2[r]){
                nums1[idx] = arr1[l];
                idx++;
                l++;
            }
            else{
                nums1[idx] = nums2[r];
                idx++;
                r++;
            }
        }

        while(l < m){
            nums1[idx] = arr1[l];
            idx++;
            l++;
        }

        while(r < n){
            nums1[idx] = nums2[r];
            idx++;
            r++;
        }

    }
};