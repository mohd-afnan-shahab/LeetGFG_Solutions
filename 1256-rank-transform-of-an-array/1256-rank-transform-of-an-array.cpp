class Solution {
public:
    // TIME COMPLEXITY - O(nLogn) and SPACE COMPLEXITY - O(n)
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tempArr = arr;
        sort(tempArr.begin(), tempArr.end());

        unordered_map<int, int> mpp;
        int rank = 1;

        for(int i = 0; i < tempArr.size(); i++){
            if(mpp.find(tempArr[i]) == mpp.end()){
                mpp[tempArr[i]] = rank;
                rank++;
            }            
        }

        for(int i = 0; i < arr.size(); i++){
            arr[i] = mpp[arr[i]];
        }

        return arr;
    }
};