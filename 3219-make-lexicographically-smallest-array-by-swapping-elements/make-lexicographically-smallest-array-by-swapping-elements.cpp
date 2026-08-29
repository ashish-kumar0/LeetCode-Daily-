class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Pair each element with its original index and sort by value
        vector<pair<int, int>> sortedPairs(n);
        for (int i = 0; i < n; ++i) {
            sortedPairs[i] = {nums[i], i};
        }
        sort(sortedPairs.begin(), sortedPairs.end());
        
        vector<int> result(n);
        int left = 0;
        
        while (left < n) {
            int right = left;
            
            // Find all elements that belong to the same connected group
            while (right + 1 < n && sortedPairs[right + 1].first - sortedPairs[right].first <= limit) {
                right++;
            }
            
            // Collect the original indices belonging to this group
            vector<int> indices;
            for (int i = left; i <= right; ++i) {
                indices.push_back(sortedPairs[i].second);
            }
            
            // Sort indices to place the smallest values at the leftmost positions
            sort(indices.begin(), indices.end());
            
            for (int i = 0; i < indices.size(); ++i) {
                result[indices[i]] = sortedPairs[left + i].first;
            }
            
            left = right + 1;
        }
        
        return result;
    }
};