class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1; // End index of the last chosen palindrome

        for (int i = 0; i < n; ++i) {
            // Check for odd-length palindrome of length k or k + 1 centered at i
            // Check for even-length palindrome centered between i and i + 1
            for (int len : {k, k + 1}) {
                int left = i - (len - 1) / 2;
                int right = i + len / 2;

                // Expand/check if the substring s[left...right] is valid
                if (left > last_end && right < n) {
                    bool is_palindrome = true;
                    int l = left, r = right;
                    while (l < r) {
                        if (s[l] != s[r]) {
                            is_palindrome = false;
                            break;
                        }
                        l++;
                        r--;
                    }

                    if (is_palindrome) {
                        count++;
                        last_end = right; // Update boundaries
                        break;           // Move to the next possible start position
                    }
                }
            }
        }

        return count;
    }
};