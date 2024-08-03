class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mpp;
        
        for(auto &num : target){
            mpp[num]++;
        }

        for(int &num : arr){
            // if koi element mila hi nahi map me
            if(mpp.find(num) == mpp.end()){
                return false;
            }

            mpp[num]--;
            if(mpp[num] == 0){
                mpp.erase(num);
            }
        }
        return mpp.size() == 0;
    }
};