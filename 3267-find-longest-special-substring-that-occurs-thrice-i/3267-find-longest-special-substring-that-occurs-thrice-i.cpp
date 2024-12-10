class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        unordered_map<string, int> mpp;

        for(int i = 0; i < n; i++){
            string current = "";

            for(int j = i; j < n; j++){
                if(current.empty() || current.back() == s[j]){
                    current.push_back(s[j]);
                    mpp[current] += 1;
                }
                else{
                    break;
                }
            }
        }

        int result = 0;
        for(auto& it : mpp){
            string str = it.first;
            if(it.second >= 3 && str.length() > result){
                result = str.length();
            }
        }

        return result == 0 ? -1 : result;
    }
};