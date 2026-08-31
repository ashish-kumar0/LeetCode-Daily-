class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;

        // Convert numbers to strings
        for (int x : nums)
            v.push_back(to_string(x));

        // Custom sorting
        sort(v.begin(), v.end(), [](string a, string b) {
            return a + b > b + a;
        });

        // If largest number is 0
        if (v[0] == "0")
            return "0";

        // Join all strings
        string ans = "";
        for (string x : v)
            ans += x;

        return ans;
    }
};