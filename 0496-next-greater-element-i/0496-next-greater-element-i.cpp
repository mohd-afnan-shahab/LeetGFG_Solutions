class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        vector<int> NGE(n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()) NGE[i] = -1;
            else{
                NGE[i] = st.top();
            }

            st.push(nums2[i]);
        }

        unordered_map<int, int> mpp;    //{nums2[i], NGE}
        for(int i = 0; i < n; i++){
            mpp[nums2[i]] = NGE[i];
        }

        vector<int> ans(nums1.size());

        for(int i = 0; i < nums1.size(); i++){
            ans[i] = mpp[nums1[i]];
        }

        return ans;
    }
};