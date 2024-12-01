class Solution {
public:
    string convert(string s, int numRows) {

        vector<string> result(numRows);
        if(numRows == 1){
            return s;
        }
        
        int idx = 0;
        bool flag = false;
        for(auto& ch : s){
            result[idx] = result[idx] + ch;

            if(idx == 0 || idx == numRows-1){
                flag = !flag;
            }

            if(flag) idx++;
            else idx--;
        }

        string zigzag = "";
        for(auto& str : result){
            zigzag += str;
        }

        return zigzag;
    }
};