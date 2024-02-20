#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    static bool compare(int a, int b) {
        string a_str = to_string(a);
        string b_str = to_string(b);
        return (a_str + b_str) > (b_str + a_str);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result = "";
        for (int num : nums) {
            result += to_string(num);
        }
        // Remove leading zeros
        size_t pos = result.find_first_not_of('0');
        if (pos != string::npos) {
            return result.substr(pos);
        }
        return "0";
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << sol.largestNumber(nums) << endl; // Output: 9534330
    return 0;
}
