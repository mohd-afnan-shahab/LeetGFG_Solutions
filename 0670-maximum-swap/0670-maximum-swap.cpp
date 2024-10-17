class Solution {
public:
    int maximumSwap(int num) {
        // convert num to string
        string str = to_string(num);

        int maxNum = num;

        for(int i = 0; i < str.size(); i++){
            for(int j = i + 1; j < str.size(); j++){
                swap(str[i], str[j]);

                int swappedNum = stoi(str);

                maxNum = max(swappedNum, maxNum);

                swap(str[i], str[j]);
            }
        }

        return maxNum;
    }
};