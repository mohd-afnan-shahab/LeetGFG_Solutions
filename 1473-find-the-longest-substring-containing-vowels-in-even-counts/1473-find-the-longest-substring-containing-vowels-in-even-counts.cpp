class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mpp;   // mask-index map

        int maxLength = 0;
        int vowelMask = 0;   // 00000
        mpp[vowelMask] = -1; // initialize mask

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a'){
                vowelMask = vowelMask ^ (1 << 0); 
            }
            else if(s[i] == 'e'){
                vowelMask = vowelMask ^ (1 << 1); 
            }
            else if(s[i] == 'i'){
                vowelMask = vowelMask ^ (1 << 2); 
            }
            else if(s[i] == 'o'){
                vowelMask = vowelMask ^ (1 << 3); 
            }
            else if(s[i] == 'u'){
                vowelMask = vowelMask ^ (1 << 4); 
            }

            if(mpp.find(vowelMask) != mpp.end()){
                maxLength = max(maxLength, i - mpp[vowelMask]); 
            }
            else{
                mpp[vowelMask] = i; // store first occurrence
            }

        }

        return maxLength;
    }
};
