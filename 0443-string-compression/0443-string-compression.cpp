class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int idx = 0;
        for(int i = 0; i < n;){
            char ch = chars[i];
            int count = 0;

            while(i < n && ch == chars[i]){
                count++;
                i++;
            }

            // if count is equal to 1
            if(count == 1){
                chars[idx] = ch;
                idx++;
            }
            else{
                chars[idx] = ch;
                idx++;
                string str = to_string(count);

                for(auto& digit : str){
                    chars[idx] = digit;
                    idx++;
                }
            }
        }

        // return chars.resize(idx);
        return idx;
    }
};