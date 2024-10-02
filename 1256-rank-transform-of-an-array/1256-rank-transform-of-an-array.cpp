class Solution {
public:
    // TIME COMPLEXITY - O(nLogn) and SPACE COMPLEXITY - O(n)
    vector<int> arrayRankTransform(vector<int>& arr) {

        if(arr.empty()) return {};
        
        vector<pair<int, int>> valueIndex;

        for(int i = 0; i < arr.size(); i++){
            valueIndex.push_back({arr[i], i});
        }

        sort(valueIndex.begin(), valueIndex.end());

        vector<int> result(arr.size());
        int rank = 1;

        result[valueIndex[0].second] = rank;

        for(int i = 1; i < valueIndex.size(); i++){
            // if current element is not equal to prev element
            if(valueIndex[i].first != valueIndex[i-1].first){
                rank++;
            }

            result[valueIndex[i].second] = rank;
        }

        return result;
    }
};