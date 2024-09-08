class Solution {
public:
    string convert2binary(int num){
        
        if(num == 0) return "0";

        string binary = "";
        while(num > 0){
            if(num % 2 == 1){
                binary = "1" + binary;
            }
            else{
                binary = "0" + binary;
            }

            num = num / 2;
        }

        return binary;
    }

    string convertDateToBinary(string date) {
        
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        string yearBinary = convert2binary(year);
        string monthBinary = convert2binary(month);
        string dayBinary = convert2binary(day);

        return (yearBinary + "-" + monthBinary + "-" + dayBinary);
    }
};

