class Solution {
public:
    string getEncryptedString(string s, int k) {

        string str = "";
        
        k = k % s.size();           // if k is large...
        for(int i = 0; i < s.size(); i++){
            
            int ind = (i + k) % s.size();      // doing mod for cyclic order..
            str += s[ind];
        }
        return str;
    }
};