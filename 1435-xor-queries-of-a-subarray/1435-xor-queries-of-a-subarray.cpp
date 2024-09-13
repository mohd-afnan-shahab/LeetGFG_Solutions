class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();

        // create cumulative xor
        vector<int> Cum_Xor(n, 0);
        Cum_Xor[0] = arr[0];
        
        for(int i = 1; i < n; i++){
            Cum_Xor[i] = Cum_Xor[i - 1] ^ arr[i];
        }

        vector<int> result;

        for(auto query : queries){
            int left = query[0];
            int right = query[1];

            int xorValue = (left == 0 ? 0 : Cum_Xor[left - 1]) ^ Cum_Xor[right];

            result.push_back(xorValue);
        }

        return result;
    }
};