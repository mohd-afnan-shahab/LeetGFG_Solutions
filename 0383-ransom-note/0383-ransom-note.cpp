class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto& mag : magazine) mp[mag]++;

        for(auto& ch : ransomNote){
            if(mp[ch] <= 0){
                return false;
            }
            else{
                mp[ch]--;
            }
        }

        return true;
    }
};