class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);

        for(auto ch : s){
            count[ch - 'a']++;
        }
        for(auto ch : t){
            count[ch - 'a']--;
        }

        //now check if all elements in count became 0 or not...
        
        //checking with lambda function.. all_of - checks for all elements..
        bool allzeroes = all_of(count.begin(), count.end(), [](int ele){
            return ele == 0;    
        });

        return allzeroes;
    }
};