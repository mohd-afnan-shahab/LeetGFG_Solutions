class Solution {
public:
    // bool canConstruct(string ransomNote, string magazine) {
    //     unordered_map<char, int> mp;
    //     for(auto& mag : magazine) mp[mag]++;

    //     for(auto& ch : ransomNote){
    //         if(mp[ch] <= 0){
    //             return false;
    //         }
    //         else{
    //             mp[ch]--;
    //         }
    //     }

    //     return true;
    // }




    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for(char c : magazine){
            freq[c - 'a']++;
        }

        for(char c : ransomNote){
            if(freq[c - 'a'] <= 0){
                return false;
            }
            freq[c - 'a']--;
        }

        return true;
    }
};