class Solution {
public:
    int countSeniors(vector<string>& details) {

        int count = 0;
        for(const auto& detail : details){
            // string age_str = detail.substr(11, 2);       //extract age
            // int age = stoi(age_str);
            
            int age = (detail[11] - '0' ) * 10 + (detail[12] - '0');

            if(age > 60){
                count++;
            }
        } 
        return count;
    }
};