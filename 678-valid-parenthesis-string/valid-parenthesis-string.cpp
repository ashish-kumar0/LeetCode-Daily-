class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // Minimum number of open '(' needed
        int high = 0;  // Maximum number of open '(' possible

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            // Can't have more ')' than can be matched
            if (high < 0) return false;

            // low cannot drop below 0 since we can treat extra '*' as empty strings
            if (low < 0) low = 0;
        }

        // Valid if it's possible to reach exactly 0 open '('
        return low == 0;
    }
};