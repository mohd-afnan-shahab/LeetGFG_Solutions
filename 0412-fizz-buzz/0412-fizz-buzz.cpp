// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//         vector<string> ans;

//         for(int i = 1; i <= n; i++){
//             if(i % 3 == 0 && i % 5 == 0) ans.push_back("FizzBuzz");
//             else if(i % 5 == 0) ans.push_back("Buzz");
//             else if(i % 3 == 0) ans.push_back("Fizz");

//             // If none of the above conditions are true, add the number itself as a string
//             else ans.push_back(to_string(i));
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);

        for(int i = 1; i <= n; i++){
            string temp = "";
            if(i % 3 == 0) temp += "Fizz";
            if(i % 5 == 0) temp += "Buzz";

            // If neither "Fizz" nor "Buzz" was added, convert the number to a string
            if(temp.empty()) temp = to_string(i);

            result[i - 1] = temp;
        }
        return result;
    }
};
