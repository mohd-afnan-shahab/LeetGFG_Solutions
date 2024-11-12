class Solution {
public:
    string reverseWords(string s) {
        vector<string> vec;

        stringstream ss(s);
        string word;

        while(ss >> word){
            vec.push_back(word);
        }

        int l = 0, r = vec.size() - 1;
        while(l < r){
            swap(vec[l], vec[r]);
            l++;
            r--;
        }

        string result;
        for(int i = 0; i < vec.size(); i++){
            result = result + vec[i];

            // add space after each word
            if(i < vec.size() - 1){
                result = result + " ";
            }

        }

        return result;
    }
};