class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        string comp = "";

        for(int i = 0; i < n;){
            char currentChar = word[i];
            int count = 0;

            while(i < n && word[i] == currentChar && count < 9){
                count++;
                i++;
            }

            comp += to_string(count) + currentChar;
        }

        return comp;
    }
};