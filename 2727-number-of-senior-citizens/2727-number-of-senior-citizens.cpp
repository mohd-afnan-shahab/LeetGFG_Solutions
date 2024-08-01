class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        string age_str;
        int count = 0;

        for(auto detail : details){
            age_str = detail.substr(11, 2);       //extract age
            int age = stoi(age_str);

            if(age > 60){
                count++;
            }
        } 
        return count;
    }
};