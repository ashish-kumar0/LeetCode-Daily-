/**
class Solution {
public:
    int strStr(string haystack, string needle) {

        size_t index = haystack.find(needle);

        if(index != string::npos){
            return index;
        }
        return -1;
    }
};
**/

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        int i = 0, j = 0;
        int index = 0;
        if (m == 0)
            return 0;
        while (i <= n - m) {
            if (haystack[i + j] == needle[j]) {
                j++;
                if (j == m) {
                    return i;
                }
            } else {
                i++;
                j = 0;
            }
        }
        return -1;
    }
};