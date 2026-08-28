class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalOR = 0;

        // Sabhi elements ka bitwise OR calculate karenge
        for (int i = 0; i < n; i++) {
            totalOR |= nums[i];
        }

        // Har set bit total 2^(n-1) subsets me contribute karti hai
        // totalOR * 2^(n-1) == totalOR << (n - 1)
        return totalOR << (n - 1);
    }
};