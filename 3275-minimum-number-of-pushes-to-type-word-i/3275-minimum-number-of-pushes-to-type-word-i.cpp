class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mpp;    //0,1,2,3,4,5,6,7,8,9

        int result = 0;
        int assign_key = 2;
        for(const auto& ch : word){
            if(assign_key > 9){
                assign_key = 2;
            }

            mpp[assign_key]++;
            result = result + mpp[assign_key];

            assign_key++;
        }
        return result;
    }
};