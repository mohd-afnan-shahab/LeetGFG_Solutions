class Solution {
public:
    string fractionAddition(string expression) {
        int nume = 0;
        int deno = 1; 

        int i = 0;
        int n = expression.length();
        while (i < n) {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expression[i] == '-');

            if (expression[i] == '+' || expression[i] == '-') {
                i++;
            }

            // Build the currNume
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';  // Converting to int
                currNume = (currNume * 10) + val;
                i++;
            }

            i++;  // To skip '/' after nume

            if (isNeg == true) {
                currNume = currNume * -1;
            }

            // Build the currDeno
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = (nume * currDeno) + (currNume * deno);
            deno = deno * currDeno;
        }

        int GCD = abs(__gcd(nume, deno));  // __gcd() is a utility

        nume = nume / GCD;
        deno = deno / GCD;

        return to_string(nume) + "/" + to_string(deno);
    }
};
