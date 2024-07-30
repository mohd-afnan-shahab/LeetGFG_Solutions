class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end()); //insert element of nums1 in st1
        unordered_set<int> st2;

        for(auto num:nums2){
            if(st1.count(num)){
                st2.insert(num);
            }
        }
        // convert the set to a vector
        vector<int> result(st2.begin(), st2.end());
        return result;
    }
};