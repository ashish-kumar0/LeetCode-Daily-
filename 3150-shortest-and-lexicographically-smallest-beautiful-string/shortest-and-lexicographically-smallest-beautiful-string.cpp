class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {

            int ones = 0;

            for (int j = i; j < n; j++) {

                if (s[j] == '1')
                    ones++;

                // We have exactly k ones
                if (ones == k) {

                    string curr = s.substr(i, j - i + 1);

                    // Case 1: Found a shorter beautiful substring
                    if (curr.length() < minLen) {
                        minLen = curr.length();
                        ans = curr;
                    }

                    // Case 2: Same length, take lexicographically smaller
                    else if (curr.length() == minLen) {
                        ans = min(ans, curr);
                    }

                    // Adding more characters will only increase length
                    // and may make number of 1s > k.
                    break;
                }

                // More than k ones -> this starting point cannot
                // produce another beautiful substring.
                if (ones > k)
                    break;
            }
        }

        return ans;
    }
};