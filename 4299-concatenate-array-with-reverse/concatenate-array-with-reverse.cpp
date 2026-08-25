class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2*n);
        // res = nums;
        for(int i=0; i<n; i++){
            res[i] = nums[i];
        }
        reverse(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            res[n+i] = nums[i];
        }

        return res;
        
    }
};