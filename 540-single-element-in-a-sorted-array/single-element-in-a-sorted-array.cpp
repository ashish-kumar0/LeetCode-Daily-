// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& arr) {
//         int st = 0, end = arr.size() - 1;

//         // Edge case: only one element
//         if (arr.size() == 1) return arr[0];

//         while (st <= end) {
//             int mid = st + (end - st) / 2;

//             // Edge cases
//             if (mid == 0 && arr[0] != arr[1]) return arr[0];
//             if (mid == arr.size() - 1 && arr[mid] != arr[mid - 1]) return arr[mid];

//             // Found unique element
//             if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
//                 return arr[mid];

//             // Check pairing pattern
//             if (mid % 2 == 0) {
//                 if (arr[mid] == arr[mid + 1]) {
//                     st = mid + 2;
//                 } else {
//                     end = mid - 1;
//                 }
//             } else {
//                 if (arr[mid] == arr[mid - 1]) {
//                     st = mid + 1;
//                 } else {
//                     end = mid - 1;
//                 }
//             }
//         }

//         return -1;  // should never reach here
//     }
// };


class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];
        
        if(nums[0] != nums[1]){
            return nums[0];
        }
        for(int i=1; i<=nums.size(); i++){
            if(nums[i-1] != nums[i] && nums[i+1] != nums[i]){
                return nums[i];
            }
        }
        return 0;
    }
};