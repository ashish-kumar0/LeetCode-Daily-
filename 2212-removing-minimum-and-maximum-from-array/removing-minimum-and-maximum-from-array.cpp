class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minEle = INT_MAX, maxEle = INT_MIN;
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minEle) {
                minEle = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxEle) {
                maxEle = nums[i];
                maxIdx = i;
            }
        }

        int leftIdx = min(minIdx, maxIdx);
        int rightIdx = max(minIdx, maxIdx);

        int ans1 = (leftIdx + 1) + (n - rightIdx);
        int ans2 = rightIdx + 1;
        int ans3 = n - leftIdx;

        return min({ans1, ans2, ans3});
    }
};