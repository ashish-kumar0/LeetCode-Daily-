class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int largest = INT_MIN;
        unordered_set<int> set;
        int  temp = k;

       for(auto x : nums){
        set.insert(x);
       }

       while(set.count(temp)){
        temp = temp+k;
       }
       return temp;
    }
};