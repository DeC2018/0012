#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> valueSymbols{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};
        string ans;

        for (const auto& [value, symbol] : valueSymbols) {
            if (num == 0)
                break;
            while (num >= value) {
                num -= value;
                ans += symbol;
            }
        }

        return ans;
    }
};

// Test function to verify the solution
void testIntToRoman(Solution& sol, int num, const string& expected) {
    string result = sol.intToRoman(num);
    cout << "Input: " << num << "\nOutput: " << result;
    if (result == expected) {
        cout << " (Correct)" << endl;
    } else {
        cout << " (Expected: " << expected << ")" << endl;
    }
    cout << "-------------------" << endl;
}

int main() {
    Solution solution;
    
    // Test cases
    testIntToRoman(solution, 3749, "MMMDCCXLIX");
    testIntToRoman(solution, 58, "LVIII");
    testIntToRoman(solution, 1994, "MCMXCIV");
    
    return 0;
}
