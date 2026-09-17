// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int count =0;

//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]!=0){
//                 swap(nums[i],nums[count]);
//                 count++;
//             }
//         }
//     }
// };


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();

        int i=1, j=0;
        while(i < n){
            if(nums[j] == 0 && nums[i] != 0){
                swap(nums[j], nums[i]);
                i++; j++;
            }else if(nums[i] == 0 && nums[j] == 0){
                i++;
            }else{
                i++;j++;
            }
        }
    }
};