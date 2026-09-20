// class Solution {
// public:
//     vector<int> largestPower(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> grp(1, nums);
//         vector<int> answer(15);

//         for (int b = 14; b >= 0; b--) {
//             int counter = 0;
//             for (int i = 0; i < grp.size(); i++) {
//                 vector<int> vone, vzero;

//                 for (int x : grp[i])
//                     (x & (1 << b) ? vone : vzero).push_back(x);
//                 if (vzero.empty()) {
//                     counter += grp[i].size();
//                     continue;
//                 }
//                 counter += vone.size();

//                 vector<vector<int>> notgrp;
//                 for (int j = 0; j < i; j++)
//                     notgrp.push_back(grp[i]);
//                 if (!vone.empty())
//                     notgrp.push_back(vone);
//                 if (!vzero.empty())
//                     notgrp.push_back(vzero);
//                 for (int j = i + 1; j < grp.size(); j++)
//                     notgrp.push_back(grp[j]);
//                 grp = notgrp;
//                 break;
//             }
//             answer[14 - b] = counter;
//         }
//         vector<int> result;
//         for (auto& x : answer)
//             result.push_back(x);
//         return result;
//     }
// };



class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<int> bits;
        for (int b = 14; b >= 0; b--) bits.push_back(b);
        vector<int> order = solve(nums, bits);

        vector<int> answer(15, 0);
        for (int idx = 0; idx < 15; idx++) {
            int b = 14 - idx, cnt = 0;
            for (int x : order) {
                if (x & (1 << b)) cnt++;
                else break;
            }
            answer[idx] = cnt;
        }
        return answer;
    }

    vector<int> solve(vector<int> S, vector<int>& bits) {
        if (S.size() <= 1 || bits.empty()) return S;
        int b = bits[0];
        vector<int> S1, S0;
        for (int x : S) (x & (1 << b) ? S1 : S0).push_back(x);

        vector<int> rest(bits.begin() + 1, bits.end());
        if (S1.empty() || S0.empty())
            return solve(S, rest);           // bit doesn't split this group, skip it

        vector<int> left = solve(S1, rest);

        // for S0, only bits where S1 is FULLY set still matter (extend the global prefix)
        vector<int> filtered;
        for (int b2 : rest) {
            bool allSet = true;
            for (int x : S1) if (!(x & (1 << b2))) { allSet = false; break; }
            if (allSet) filtered.push_back(b2);
        }
        vector<int> right = solve(S0, filtered);

        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};