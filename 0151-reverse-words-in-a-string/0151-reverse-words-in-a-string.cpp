class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        string result = "";

        stringstream ss(s);
        string word;

        while(ss >> word){
            result = word + " " + result;
        }

        return result.substr(0, result.length() - 1);
    }
};