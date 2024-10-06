class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        // assume s1 is always longer than or equal to s2
        if (s1.size() < s2.size()) swap(s1, s2);

        // Split s1 and s2 into words
        vector<string> v1 = splitSentence(s1);
        vector<string> v2 = splitSentence(s2);

        int i = 0, j = v1.size() - 1; // for s1
        int l = 0, r = v2.size() - 1; // for s2

        // Check for matches from the start
        while (i < v1.size() && l < v2.size() && v1[i] == v2[l]) {
            i++; 
            l++;
        }

        // Check for matches from the end
        while (r >= l && v2[r] == v1[j]) {
            j--; 
            r--;
        }

        return r < l;
    }

private:
    // Helper function to split sentence into words
    vector<string> splitSentence(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
