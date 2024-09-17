class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> mpp;

        istringstream iss1(s1), iss2(s2);
        string word;

        // extract words from s1
        while(iss1 >> word){
            mpp[word]++;
        }

        while(iss2 >> word){
            mpp[word]++;
        }

        vector<string> ans;
        
        // iterate in map
        for(auto word : mpp){
            if(word.second == 1){
                ans.push_back(word.first);
            }
        }

        return ans;
    }
};