class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int sum = 0;
        for(int i = 0; i<n; i++){
            char ch = s[i];
            int val = 'z' - int(ch) + 1;
            sum = sum + val*(i+1);
        }
        return sum;
    }
};