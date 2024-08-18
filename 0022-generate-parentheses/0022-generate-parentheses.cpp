class Solution {
public:
    void parenthesis(int n, int L, int R, 
                     vector<string>& ans, 
                     string& temp)
    {
        // BASE CASE
        if(L + R == 2 * n){
            ans.push_back(temp);
            return;
        }
        // if considering Left one
        if(L < n){
            temp.push_back('(');
            parenthesis(n, L + 1, R, ans, temp);
            temp.pop_back();
        }

        // if considering Right one
        if(R < L){
            temp.push_back(')');
            parenthesis(n, L, R + 1, ans, temp);
            temp.pop_back();
        } 
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        parenthesis(n, 0, 0, ans, temp);
        return ans;
    }
};
